#!/bin/bash
set -u
set -o pipefail

#########################################
# CONFIGURAÇÃO
#########################################

URL_CORRETOR_T1="../trabalho1/corretor-final.c"
URL_CORRETOR_T2="../trabalho2/mainTeste.c"

CORRETOR_T1="$URL_CORRETOR_T1"
CORRETOR_T2="$URL_CORRETOR_T2"

REPOS_DIR="./repos"
RESULT_DIR="./resultados"
REPOS_FILE="./repos.txt"
OUTPUT_CSV="$RESULT_DIR/notas.csv"

mkdir -p "$REPOS_DIR" "$RESULT_DIR"

#########################################
# PARÂMETROS
#########################################

DO_CLONE=0
ONLY_ALUNO=""

CORRIGE_T1=0
CORRIGE_T2=0

while [[ $# -gt 0 ]]; do
    case "$1" in
        -c|-clone)
            DO_CLONE=1
            shift
            ;;
        -a|-aluno)
            ONLY_ALUNO="$2"
            shift 2
            ;;
        -t1)
            CORRIGE_T1=1
            shift
            ;;
        -t2)
            CORRIGE_T2=1
            shift
            ;;
        *)
            echo "Parâmetro desconhecido: $1"
            echo "Uso: ./corrigir.sh [-c|-clone] [-a|-aluno nome] [-t1] [-t2]"
            exit 1
            ;;
    esac
done

# Se nenhum trabalho foi especificado, corrige ambos
if [[ $CORRIGE_T1 -eq 0 && $CORRIGE_T2 -eq 0 ]]; then
    CORRIGE_T1=1
    CORRIGE_T2=1
fi

#########################################
# TIMEOUT
#########################################

if command -v timeout >/dev/null 2>&1; then
    TIMEOUT_CMD="timeout"
elif command -v gtimeout >/dev/null 2>&1; then
    TIMEOUT_CMD="gtimeout"
else
    TIMEOUT_CMD=""
    echo "⚠ timeout não encontrado"
fi

#########################################
# CSV HEADER
#########################################

header="aluno"

[[ $CORRIGE_T1 -eq 1 ]] && header+=",t1_acertos,t1_erros,t1_nota,t1_obs"
[[ $CORRIGE_T2 -eq 1 ]] && header+=",t2_acertos,t2_erros,t2_nota,t2_obs"

header+=",nota_final"

echo "$header" > "$OUTPUT_CSV"

#########################################
# CLONE
#########################################

if [[ "$DO_CLONE" -eq 1 ]]; then
    if [[ ! -f "$REPOS_FILE" ]]; then
        echo "Erro: repos.txt não encontrado"
        exit 1
    fi

    while IFS= read -r url || [[ -n "$url" ]]; do
        [[ -z "$url" || "$url" =~ ^# ]] && continue
        name=$(basename "$url" .git)

        [[ -n "$ONLY_ALUNO" && "$name" != *"$ONLY_ALUNO"* ]] && continue

        if [[ -d "$REPOS_DIR/$name" ]]; then
            echo "📁 $name já existe"
            continue
        fi

        echo "🔽 Clonando $name"
        git clone "$url" "$REPOS_DIR/$name" &> "$REPOS_DIR/$name.clone.log"
    done < "$REPOS_FILE"
fi

#########################################
# FUNÇÃO DE CORREÇÃO
#########################################

corrigir_trabalho() {
    local aluno_dir="$1"
    local trabalho="$2"
    local corretor="$3"

    local tdir="$aluno_dir/$trabalho"
    local cfile="$tdir/$trabalho.c"
    local hfile="$tdir/$trabalho.h"
    local bin="$aluno_dir/${trabalho}_prog"

    if [[ ! -d "$tdir" ]]; then
        echo "0,0,0,Pasta inexistente"
        return
    fi

    if [[ ! -f "$cfile" || ! -f "$hfile" ]]; then
        echo "0,0,0,Arquivos ausentes"
        return
    fi

    gcc "$corretor" "$cfile" -I"$tdir" -o "$bin" &> "$aluno_dir/${trabalho}_compile.log"
    [[ $? -ne 0 ]] && { echo "0,0,0,Erro de compilacao"; return; }

    if [[ -n "$TIMEOUT_CMD" ]]; then
        result=$($TIMEOUT_CMD 5s "$bin" 2> "$aluno_dir/${trabalho}_exec.log")
        status=$?
    else
        result=$("$bin" 2> "$aluno_dir/${trabalho}_exec.log")
        status=$?
    fi

    [[ $status -ne 0 ]] && { echo "0,0,0,Erro de execucao"; return; }

    acertos=$(printf "%s" "$result" | tr ' ' '\n' | grep -x 1 | wc -l)
    erros=$(printf "%s" "$result" | tr ' ' '\n' | grep -x 0 | wc -l)
    total=$((acertos + erros))

    if [[ $total -gt 0 ]]; then
        nota=$(awk "BEGIN{printf \"%.2f\", ($acertos/$total)*10}")
    else
        nota="0.00"
    fi

    echo "$acertos,$erros,$nota,"
}

#########################################
# CORREÇÃO
#########################################

for aluno_dir in "$REPOS_DIR"/*; do
    [[ -d "$aluno_dir" ]] || continue
    aluno=$(basename "$aluno_dir")

    [[ -n "$ONLY_ALUNO" && "$aluno" != *"$ONLY_ALUNO"* ]] && continue

    echo "📝 Corrigindo $aluno"

    linha="$aluno"
    soma_notas=0
    qtd_trabalhos=0

    if [[ $CORRIGE_T1 -eq 1 ]]; then
        t1=$(corrigir_trabalho "$aluno_dir" "trabalho1" "$CORRETOR_T1")
        linha+=",$t1"
        nota_t1=$(echo "$t1" | cut -d',' -f3)
        soma_notas=$(awk "BEGIN{print $soma_notas + $nota_t1}")
        qtd_trabalhos=$((qtd_trabalhos + 1))
    fi

    if [[ $CORRIGE_T2 -eq 1 ]]; then
        t2=$(corrigir_trabalho "$aluno_dir" "trabalho2" "$CORRETOR_T2")
        linha+=",$t2"
        nota_t2=$(echo "$t2" | cut -d',' -f3)
        soma_notas=$(awk "BEGIN{print $soma_notas + $nota_t2}")
        qtd_trabalhos=$((qtd_trabalhos + 1))
    fi

    if [[ $qtd_trabalhos -gt 0 ]]; then
        nota_final=$(awk "BEGIN{printf \"%.2f\", $soma_notas / $qtd_trabalhos}")
    else
        nota_final="0.00"
    fi

    linha+=",$nota_final"
    echo "$linha" >> "$OUTPUT_CSV"
done

echo "✔ Correção finalizada"
echo "📄 CSV: $OUTPUT_CSV"
