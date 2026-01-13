📘 README — Script de Correção Automática de Trabalhos (C)

Este projeto contém um script Bash para clonar repositórios de alunos, compilar e corrigir automaticamente trabalhos em C usando corretores externos, gerando um arquivo CSV com notas e observações.

Atualmente, o script suporta:

✅ Trabalho 1

✅ Trabalho 2

✅ Expansão fácil para trabalhos futuros

📁 Estrutura de Diretórios

A estrutura esperada do projeto é:

.
├── trabalho1/
│   └── corretor-final.c
│
├── trabalho2/
│   └── mainTeste.c
│
└── scripts/
    ├── corrigir.sh
    ├── repos.txt
    ├── repos/
    │   ├── INF029-Aluno1/
    │   │   ├── trabalho1/
    │   │   └── trabalho2/
    │   └── INF029-Aluno2/
    └── resultados/
        └── notas.csv

🧪 Estrutura esperada dos trabalhos dos alunos
📌 Trabalho 1

Dentro do repositório do aluno:

trabalho1/
├── trabalho1.c
└── trabalho1.h

📌 Trabalho 2

Dentro do repositório do aluno:

trabalho2/
├── trabalho2.c
└── trabalho2.h


⚠️ O main() não vem do aluno, mas sim do corretor oficial.

🧠 Funcionamento geral do script

O script:

(Opcionalmente) clona os repositórios listados em repos.txt

Para cada aluno:

compila o trabalho junto com o corretor oficial

executa o programa

conta quantos 1 (acertos) e 0 (erros) foram impressos

calcula a nota (0 a 10)

Gera um CSV consolidado, com:

acertos

erros

nota por trabalho

observações de erro

nota final (média dos trabalhos corrigidos)

⚠️ Erros de compilação ou execução não interrompem o script.

📄 Arquivo repos.txt

O arquivo repos.txt deve ficar dentro da pasta scripts/
Cada linha contém uma URL de repositório Git:

https://github.com/usuario/INF029-RenatoNovais.git
https://github.com/usuario/INF029-LeticiaGomes.git


Linhas vazias ou iniciadas com # são ignoradas.

▶️ Como executar

Entre na pasta scripts:

cd scripts


Dê permissão de execução (apenas uma vez):

chmod +x corrigir.sh

⚙️ Opções disponíveis
🔹 Clonar repositórios
./corrigir.sh -c
./corrigir.sh -clone

🔹 Corrigir sem clonar (usa o que já está em repos/)
./corrigir.sh

🔹 Corrigir apenas um aluno
./corrigir.sh -a Renato
./corrigir.sh -aluno Renato

🔹 Corrigir apenas Trabalho 1
./corrigir.sh -t1

🔹 Corrigir apenas Trabalho 2
./corrigir.sh -t2

🔹 Combinações possíveis
# Clonar e corrigir só o Trabalho 1
./corrigir.sh -c -t1

# Corrigir só o Trabalho 2 de um aluno específico
./corrigir.sh -t2 -a Leticia

📊 Arquivo de saída (notas.csv)

O CSV é gerado em:

scripts/resultados/notas.csv


Exemplo de colunas:

aluno,
t1_acertos,t1_erros,t1_nota,t1_obs,
t2_acertos,t2_erros,t2_nota,t2_obs,
nota_final


A nota final é a média aritmética dos trabalhos corrigidos na execução

O arquivo é sempre sobrescrito a cada execução

🚨 Tratamento de erros

O script detecta automaticamente:

❌ Pasta do trabalho inexistente

❌ Arquivos .c ou .h ausentes

❌ Erro de compilação

❌ Erro de execução

⏱️ Timeout (se disponível no sistema)

Esses problemas são registrados na coluna observação do CSV.

🧩 Expansão futura

O script foi escrito para facilitar extensões como:

Trabalho 3, 4, 5…

Pesos diferentes por trabalho

Nota mínima obrigatória

Geração de relatórios individuais

Execução paralela

Exportação para PDF

🧑‍🏫 Público-alvo

Este script é ideal para:

professores

monitores

disciplinas de programação em C

turmas grandes com correção automática

✅ Conclusão

Este projeto fornece uma solução robusta, reutilizável e extensível para correção automática de trabalhos em C, com foco em produtividade, clareza e segurança.

Se quiser evoluir ainda mais, é só pedir 🚀