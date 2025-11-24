#!/bin/bash
set -u
set -o pipefail

###############################################
# CONFIGURAÇÕES
###############################################

# Diretórios (tudo dentro de scripts/)
BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
REPOS_DIR="$BASE_DIR/repos"
RESULT_DIR="$BASE_DIR/resultados"
REPOS_FILE="$BASE_DIR/repos.txt"

# Corretor do Trabalho 1
URL_CORRETOR_T1="../trabalho1/corretor-final.c"
CORRETOR_T1="$BASE_DIR/$URL_CORRETOR_T1"

# Arquivo CSV
OUTPUT_CSV="$RESULT_DIR/notas.csv"

mkdir -p "$REPOS_DIR"
mkdir -p "$RESULT_DIR"

###############################################
# PARÂMETROS
###############################################
DO_CLONE="0"
run_only_one=""

while [[ $# -gt 0 ]]; do
    case "$1" in
        -c|-clone)
            DO_CLONE="1"
            shift
            ;;
        -a|-aluno)
            if [[ -z "${2-}" ]]; then
                echo "Erro: faltando nome após -a / -aluno"
                exit 1
            fi
            run_only_one="$2"
            shift 2
            ;;
        *)
            echo "Parâmetro desconhecido: $1"
            echo "Uso: ./corrigir.sh [-c | -clone] [-a aluno | -aluno aluno]"
            exit 1
            ;;
    esac
done

###############################################
# TIMEOUT (Linux: timeout | macOS: gtimeout)
###############################################
detect_timeout() {
    if command -v timeout >/dev/null 2>&1; then
        TIMEOUT_CMD="timeout"
    elif command -v gtimeout >/dev/null 2>&1; then
        TIMEOUT_CMD="gtimeout"
    else
        TIMEOUT_CMD=""
        echo "⚠ Nenhum comando timeout encontrado. Execução sem limite."
    fi
}
detect_timeout

###############################################
# FUNÇÃO: CLONAR REPOSITÓRIOS
###############################################
clone_repo() {
    local url="$1"
    local name
    name=$(basename "$url" .git)

    # Filtro do -a (aluno)
    if [[ -n "$run_only_one" && "$name" != *"$run_only_one"* ]]; then
        return
    fi

    if [[ -d "$REPOS_DIR/$name" ]]; then
        echo "📁 Repositório '$name' já existe — pulando."
        return
    fi

    echo "🔽 Clonando $name..."
    if ! git clone "$url" "$REPOS_DIR/$name" &> "$REPOS_DIR/$name.clone.log"; then
        echo "❌ Erro ao clonar $name"
        echo "$name,0,0,0,Erro ao clonar repositório" >> "$OUTPUT_CSV"
        return
    fi
}

###############################################
# FUNÇÃO: CORRIGIR ALUNO
###############################################
corrigir_aluno() {
    local aluno_dir="$1"
    local aluno_name
    aluno_name=$(basename "$aluno_dir")

    echo "📝 Corrigindo $aluno_name..."

    local trabalho_dir="$aluno_dir/trabalho1"

    if [[ ! -d "$trabalho_dir" ]]; then
        echo "⚠ $aluno_name não possui pasta trabalho1"
        echo "$aluno_name,0,0,0,Pasta trabalho1 não encontrada" >> "$OUTPUT_CSV"
        return
    fi

    local ALUNO_C="$trabalho_dir/trabalho1.c"
    local ALUNO_H="$trabalho_dir/trabalho1.h"

    if [[ ! -f "$ALUNO_C" || ! -f "$ALUNO_H" ]]; then
        echo "⚠ Arquivos trabalho1.c ou trabalho1.h faltando"
        echo "$aluno_name,0,0,0,Arquivos faltando" >> "$OUTPUT_CSV"
        return
    fi

    gcc "$CORRETOR_T1" "$ALUNO_C" -I"$trabalho_dir" -o "$aluno_dir/prog" \
        &> "$aluno_dir/erro_compilacao.txt"

    if [[ $? -ne 0 ]]; then
        echo "❌ Falha na compilação de $aluno_name"
        echo "$aluno_name,0,0,0,Erro de compilacao" >> "$OUTPUT_CSV"
        return
    fi

    # Execução (com timeout se existir)
    local result exec_status
    if [[ -n "${TIMEOUT_CMD}" ]]; then
        result=$($TIMEOUT_CMD 5s "$aluno_dir/prog" 2> "$aluno_dir/erro_execucao.txt")
        exec_status=$?
    else
        result=$("$aluno_dir/prog" 2> "$aluno_dir/erro_execucao.txt")
        exec_status=$?
    fi

    if [[ $exec_status -ne 0 ]]; then
        case "$exec_status" in
            124)
                echo "❌ Timeout em $aluno_name"
                echo "$aluno_name,0,0,0,timeout" >> "$OUTPUT_CSV"
                ;;
            139)
                echo "❌ Segmentation fault em $aluno_name"
                echo "$aluno_name,0,0,0,segmentation fault" >> "$OUTPUT_CSV"
                ;;
            *)
                echo "❌ Erro de execução em $aluno_name"
                echo "$aluno_name,0,0,0,Erro de execucao" >> "$OUTPUT_CSV"
                ;;
        esac
        return
    fi

    # Contagem
    local acertos erros total nota
    acertos=$(printf "%s" "$result" | tr -s '[:space:][:punct:]' '\n' | grep -x '1' | wc -l)
    erros=$(printf "%s" "$result" | tr -s '[:space:][:punct:]' '\n' | grep -x '0' | wc -l)
    total=$((acertos + erros))

    if [[ $total -gt 0 ]]; then
        nota=$(awk "BEGIN { printf \"%.2f\", ($acertos/$total)*10 }")
    else
        nota="0.00"
    fi

    echo "✔ $aluno_name → acertos: $acertos | erros: $erros | nota: $nota"
    echo "$aluno_name,$acertos,$erros,$nota," >> "$OUTPUT_CSV"
}

###############################################
# ETAPA 1 — CLONAR (somente se -c)
###############################################

if [[ "$DO_CLONE" == "1" ]]; then
    if [[ ! -f "$REPOS_FILE" ]]; then
        echo "Erro: arquivo repos.txt não encontrado em $BASE_DIR"
        exit 1
    fi

    echo "Criando CSV do zero..."
    echo "aluno,acertos,erros,nota,observacao" > "$OUTPUT_CSV"

    while IFS= read -r url || [[ -n "$url" ]]; do
        [[ -z "$url" ]] && continue
        [[ "$url" =~ ^[[:space:]]*# ]] && continue
        clone_repo "$url"
    done < "$REPOS_FILE"
else
    # Se não clonar, recria o CSV mesmo assim
    echo "aluno,acertos,erros,nota,observacao" > "$OUTPUT_CSV"
fi

###############################################
# ETAPA 2 — RODAR CORREÇÕES
###############################################

for aluno_dir in "$REPOS_DIR"/*; do
    [[ -d "$aluno_dir" ]] || continue

    if [[ -n "$run_only_one" && "$(basename "$aluno_dir")" != *"$run_only_one"* ]]; then
        continue
    fi

    corrigir_aluno "$aluno_dir"
done

echo ""
echo "📊 Correção concluída! CSV em:"
echo "➡ $OUTPUT_CSV"
