#!/bin/bash

#############################################
# DIRETÓRIO DO SCRIPT
#############################################

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

#############################################
# CONFIGURAÇÕES
#############################################

REPOS_DIR="$SCRIPT_DIR/repos"
RESULTADOS_DIR="$SCRIPT_DIR/resultados"
DEBUG_DIR="$SCRIPT_DIR/debug"

ARQUIVO_REPOS="$SCRIPT_DIR/repos.txt"
CSV_SAIDA="$RESULTADOS_DIR/notas.csv"

URL_CORRETOR_T1="$SCRIPT_DIR/../trabalho1/corretor-final.c"
URL_CORRETOR_T2="$SCRIPT_DIR/../trabalho2/mainTeste.c"

PENALIDADE_SEGFAULT=2.0

#############################################
# FLAGS
#############################################

DO_CLONE=false
CORRIGIR_T1=false
CORRIGIR_T2=false
ALUNO_ESPECIFICO=""
DO_CLEAN=false
DEBUG=false

#############################################
# PARÂMETROS
#############################################

while [[ $# -gt 0 ]]; do
    case "$1" in
        -c|-clone) DO_CLONE=true ;;
        -t1) CORRIGIR_T1=true ;;
        -t2) CORRIGIR_T2=true ;;
        -clean) DO_CLEAN=true ;;
        -debug) DEBUG=true ;;
        -a|-aluno)
            shift
            ALUNO_ESPECIFICO="$1"
            ;;
        *)
            echo "Parâmetro desconhecido: $1"
            exit 1
            ;;
    esac
    shift
done

if ! $CORRIGIR_T1 && ! $CORRIGIR_T2; then
    CORRIGIR_T1=true
    CORRIGIR_T2=true
fi

#############################################
# FUNÇÕES
#############################################

contar_testes_corretor() {
    grep -E '^[[:space:]]*printf\s*\(\s*"%d\\n"\s*,.*==.*\);' "$1" \
        | grep -v '^[[:space:]]*//' \
        | wc -l
}

corrigir_trabalho_isolado() {
    local aluno="$1"
    local trabalho="$2"
    local arquivo_c="$3"
    local arquivo_h="$4"
    local corretor="$5"
    local total_testes="$6"

    local acertos=0
    local falhas=0
    local obs=""
    local nota="0.00"

    TMP_DIR=$(mktemp -d)

    cp "$corretor" "$TMP_DIR/"
    cp "$arquivo_c" "$TMP_DIR/"
    [[ -f "$arquivo_h" ]] && cp "$arquivo_h" "$TMP_DIR/"

    cd "$TMP_DIR" || exit 1

    gcc "$(basename "$corretor")" "$(basename "$arquivo_c")" \
        -o exec 2>compile.err

    if [[ $? -ne 0 ]]; then
        if $DEBUG; then
            mkdir -p "$DEBUG_DIR/$aluno"
            cp compile.err "$DEBUG_DIR/$aluno/${trabalho}.compile"
        fi
        cd - >/dev/null
        rm -rf "$TMP_DIR"
        echo "0,0,0.00,erro de compilacao"
        return
    fi

    ./exec >stdout.out 2>stderr.err
    status=$?

    acertos=$(tr -cs '01' '\n' < stdout.out | grep -c '^1$')
    falhas=$(tr -cs '01' '\n' < stdout.out | grep -c '^0$')

    nota=$(awk -v a="$acertos" -v t="$total_testes" '
        BEGIN {
            if (t > 0) printf "%.2f", (a/t)*10;
            else print "0.00";
        }
    ')

    if [[ $status -ne 0 ]]; then
        obs="segmentation fault"
        nota=$(awk -v n="$nota" -v p="$PENALIDADE_SEGFAULT" '
            BEGIN {
                r = n - p
                if (r < 0) r = 0
                printf "%.2f", r
            }
        ')
    fi

    if $DEBUG; then
        mkdir -p "$DEBUG_DIR/$aluno"
        cp stdout.out "$DEBUG_DIR/$aluno/${trabalho}.out"
        cp stderr.err "$DEBUG_DIR/$aluno/${trabalho}.err"
    fi

    cd - >/dev/null
    rm -rf "$TMP_DIR"

    echo "$acertos,$falhas,$nota,$obs"
}

#############################################
# PREPARAÇÃO
#############################################

mkdir -p "$REPOS_DIR" "$RESULTADOS_DIR"
$DEBUG && mkdir -p "$DEBUG_DIR"

echo "aluno,t1_acertos,t1_falhas,t1_nota,t1_obs,t2_acertos,t2_falhas,t2_nota,t2_obs,nota_final" > "$CSV_SAIDA"

TOTAL_TESTES_T1=0
TOTAL_TESTES_T2=0

$CORRIGIR_T1 && TOTAL_TESTES_T1=$(contar_testes_corretor "$URL_CORRETOR_T1")
$CORRIGIR_T2 && TOTAL_TESTES_T2=$(contar_testes_corretor "$URL_CORRETOR_T2")

#############################################
# CLONE
#############################################

if $DO_CLONE; then
    echo "==> Clonando repositórios"

    [[ ! -f "$ARQUIVO_REPOS" ]] && {
        echo "ERRO: repos.txt não encontrado"
        exit 1
    }

    while IFS= read -r repo || [[ -n "$repo" ]]; do
        [[ -z "$repo" || "$repo" =~ ^# ]] && continue

        nome=$(basename "$repo" .git)
        echo "   -> Clonando $nome"

        rm -rf "$REPOS_DIR/$nome"
        git clone "$repo" "$REPOS_DIR/$nome" >"$REPOS_DIR/$nome.clone.log" 2>&1
    done < "$ARQUIVO_REPOS"
fi

#############################################
# CLEAN
#############################################

if $DO_CLEAN; then
    echo "==> Limpando ambiente"
    rm -rf "$REPOS_DIR"/*
    rm -rf "$RESULTADOS_DIR"/*
    rm -rf "$DEBUG_DIR"/*
fi

#############################################
# CORREÇÃO
#############################################

for aluno_dir in "$REPOS_DIR"/*; do
    [[ ! -d "$aluno_dir" ]] && continue

    aluno=$(basename "$aluno_dir")
    [[ "$aluno" == *.clone.log ]] && continue
    [[ -n "$ALUNO_ESPECIFICO" && "$aluno" != "$ALUNO_ESPECIFICO" ]] && continue

    echo "==> Corrigindo $aluno"

    t1_ac=0; t1_fa=0; t1_no="0.00"; t1_obs=""
    t2_ac=0; t2_fa=0; t2_no="0.00"; t2_obs=""

    if $CORRIGIR_T1 && [[ -d "$aluno_dir/trabalho1" ]]; then
        echo "   - Trabalho 1"
        IFS=',' read t1_ac t1_fa t1_no t1_obs < <(
            corrigir_trabalho_isolado \
                "$aluno" "t1" \
                "$aluno_dir/trabalho1/trabalho1.c" \
                "$aluno_dir/trabalho1/trabalho1.h" \
                "$URL_CORRETOR_T1" \
                "$TOTAL_TESTES_T1"
        )
    fi

    if $CORRIGIR_T2 && [[ -d "$aluno_dir/trabalho2" ]]; then
        echo "   - Trabalho 2"
        IFS=',' read t2_ac t2_fa t2_no t2_obs < <(
            corrigir_trabalho_isolado \
                "$aluno" "t2" \
                "$aluno_dir/trabalho2/trabalho2.c" \
                "$aluno_dir/trabalho2/trabalho2.h" \
                "$URL_CORRETOR_T2" \
                "$TOTAL_TESTES_T2"
        )
    fi

    nota_final=$(awk -v n1="$t1_no" -v n2="$t2_no" '
        BEGIN { printf "%.2f", (n1 + n2) / 2 }
    ')

    echo "$aluno,$t1_ac,$t1_fa,$t1_no,$t1_obs,$t2_ac,$t2_fa,$t2_no,$t2_obs,$nota_final" >> "$CSV_SAIDA"
done
