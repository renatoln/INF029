#!/bin/bash
set -u
set -o pipefail

# Configurações
REPOS_FILE="repos.txt"
CORRETOR="./corretor.c"
REPOS_DIR="repos"
RESULT_DIR="resultados"
OUTPUT_CSV="$RESULT_DIR/notas.csv"

# Estado
DO_CLONE=0
RUN_ONLY_ONE=""

# Cria pastas
mkdir -p "$REPOS_DIR"
mkdir -p "$RESULT_DIR"

#########################################
# PARÂMETROS DE LINHA DE COMANDO
#########################################
while [[ $# -gt 0 ]]; do
    case "$1" in
        -clone)
            DO_CLONE=1
            shift
            ;;
        -aluno)
            RUN_ONLY_ONE="$2"
            shift 2
            ;;
        *)
            echo "Parâmetro desconhecido: $1"
            echo "Uso: ./corrigir.sh [-clone] [-aluno NOME]"
            exit 1
            ;;
    esac
done

#########################################
# INICIALIZA CSV (sempre sobrescreve)
#########################################
echo "aluno,acertos,erros,nota,observacao" > "$OUTPUT_CSV"

#########################################
# DETECTAR TIMEOUT
#########################################
detect_timeout() {
    if command -v timeout >/dev/null 2>&1; then
        TIMEOUT_CMD="timeout"
    elif command -v gtimeout >/dev/null 2>&1; then
        TIMEOUT_CMD="gtimeout"
    else
        TIMEOUT_CMD=""
        echo "⚠️  Nenhum timeout/gtimeout encontrado. Execuções SEM limite."
    fi
}
detect_timeout

#########################################
# FUNÇÃO: CLONAR
#########################################
clone_repo() {
    local url="$1"
    local name
    name=$(basename "$url" .git)

    # filtro -aluno
    if [[ -n "$RUN_ONLY_ONE" && "$name" != *"$RUN_ONLY_ONE"* ]]; then
        return
    fi

    if [[ -d "$REPOS_DIR/$name" ]]; then
        echo "📁 Repo '$name' já existe. Pulando clone."
        return
    fi

    echo "🔽 Clonando $name..."
    if ! git clone "$url" "$REPOS_DIR/$name" &> "$REPOS_DIR/$name.clone.log"; then
        echo "❌ Erro ao clonar $name"
        echo "$name,0,0,0,Erro ao clonar repositorio" >> "$OUTPUT_CSV"
        return
    fi
}

#########################################
# FUNÇÃO: CORRIGIR ALUNO
#########################################
corrigir_aluno() {
    local aluno_dir="$1"
    local aluno_name
    aluno_name=$(basename "$aluno_dir")

    echo "📝 Corrigindo $aluno_name..."

    local trabalho_dir="$aluno_dir/trabalho1"

    if [[ ! -d "$trabalho_dir" ]]; then
        echo "⚠️  Sem trabalho1"
        echo "$aluno_name,0,0,0,Pasta trabalho1 nao encontrada" >> "$OUTPUT_CSV"
        return
    fi

    local ALUNO_C="$trabalho_dir/trabalho1.c"
    local ALUNO_H="$trabalho_dir/trabalho1.h"

    if [[ ! -f "$ALUNO_C" || ! -f "$ALUNO_H" ]]; then
        echo "⚠️  Arquivos faltando"
        echo "$aluno_name,0,0,0,Faltam arquivos" >> "$OUTPUT_CSV"
        return
    fi

    gcc "$CORRETOR" "$ALUNO_C" -I"$trabalho_dir" -o "$aluno_dir/prog" &> "$aluno_dir/erro_compilacao.txt"
    if [[ $? -ne 0 ]]; then
        echo "❌ Falha de compilação"
        echo "$aluno_name,0,0,0,Erro de compilacao" >> "$OUTPUT_CSV"
        return
    fi

    local result exec_status
    if [[ -n "$TIMEOUT_CMD" ]]; then
        result=$($TIMEOUT_CMD 5s "$aluno_dir/prog" 2> "$aluno_dir/erro_execucao.txt")
        exec_status=$?
    else
        result=$("$aluno_dir/prog" 2> "$aluno_dir/erro_execucao.txt")
        exec_status=$?
    fi

    if [[ $exec_status -ne 0 ]]; then
        if [[ $exec_status -eq 124 ]]; then
            echo "$aluno_name,0,0,0,timeout" >> "$OUTPUT_CSV"
        elif [[ $exec_status -eq 139 ]]; then
            echo "$aluno_name,0,0,0,segmentation fault" >> "$OUTPUT_CSV"
        else
            echo "$aluno_name,0,0,0,Erro de execucao" >> "$OUTPUT_CSV"
        fi
        return
    fi

    # Contagens exatas de tokens "1" e "0"
    local acertos erros total nota
    acertos=$(printf "%s" "$result" | tr -s '[:space:][:punct:]' '\n' | grep -x '1' | wc -l)
    erros=$(printf "%s" "$result" | tr -s '[:space:][:punct:]' '\n' | grep -x '0' | wc -l)
    total=$((acertos + erros))

    if [[ $total -gt 0 ]]; then
        nota=$(awk "BEGIN { printf \"%.2f\", ($acertos/$total)*10 }")
    else
        nota="0.00"
    fi

    echo "✔ $aluno_name → $acertos acertos | $erros erros | nota $nota"
    echo "$aluno_name,$acertos,$erros,$nota," >> "$OUTPUT_CSV"
}

#########################################
# 1) CLONAR repositórios **somente se -clone for usado**
#########################################
if [[ $DO_CLONE -eq 1 ]]; then

    if [[ ! -f "$REPOS_FILE" ]]; then
        echo "Erro: $REPOS_FILE não existe."
        exit 1
    fi

    echo "🔧 Modo clone ativado."
    while IFS= read -r url || [[ -n "$url" ]]; do
        [[ -z "$url" ]] && continue
        [[ "$url" =~ ^[[:space:]]*# ]] && continue
        clone_repo "$url"
    done < "$REPOS_FILE"
else
    echo "⏩ Ignorando clonagem (rodando somente correção)."
fi

#########################################
# 2) CORRIGIR TODOS OS REPOS CLONADOS
#########################################
for aluno_dir in "$REPOS_DIR"/*; do
    [[ -d "$aluno_dir" ]] || continue

    if [[ -n "$RUN_ONLY_ONE" && "$(basename "$aluno_dir")" != *"$RUN_ONLY_ONE"* ]]; then
        continue
    fi

    corrigir_aluno "$aluno_dir"
done

echo ""
echo "📊 Correção finalizada! Arquivo gerado em:"
echo "   $OUTPUT_CSV"
