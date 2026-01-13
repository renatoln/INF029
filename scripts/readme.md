# 📘 Script de Correção Automática de Trabalhos em C

Este projeto contém um **script Bash** para **clonar repositórios de alunos**, **compilar** e **corrigir automaticamente** trabalhos em linguagem C, utilizando **corretores oficiais**, e gerando um **arquivo CSV com notas, erros e observações**.

O script foi projetado para uso acadêmico (professores e monitores) e é facilmente extensível para novos trabalhos.

---

## 📁 Estrutura de Diretórios

A estrutura esperada do projeto é:

.
├── trabalho1/
│ └── corretor-final.c
│
├── trabalho2/
│ └── mainTeste.c
│
└── scripts/
├── corrigir.sh
├── repos.txt
├── repos/
│ ├── INF029-Aluno1/
│ │ ├── trabalho1/
│ │ └── trabalho2/
│ └── INF029-Aluno2/
└── resultados/
└── notas.csv

---

## 🧪 Estrutura esperada dos trabalhos dos alunos

### Trabalho 1

Dentro do repositório do aluno:

trabalho1/
├── trabalho1.c
└── trabalho1.h

O `main()` é fornecido pelo corretor oficial (`corretor-final.c`).

---

### Trabalho 2

Dentro do repositório do aluno:

trabalho2/
├── trabalho2.c
└── trabalho2.h


O `main()` é fornecido pelo corretor oficial (`mainTeste.c`).

---

## 📄 Arquivo repos.txt

O arquivo `repos.txt` deve estar dentro da pasta `scripts/`.

Cada linha contém a URL de um repositório Git:

https://github.com/usuario/INF029-RenatoNovais.git
https://github.com/usuario/INF029-LeticiaGomes.git


- Linhas vazias são ignoradas
- Linhas iniciadas com `#` são tratadas como comentário

---

## ⚙️ Funcionalidades do script

O script:

- Clona repositórios (opcional)
- Compila trabalhos junto com o corretor oficial
- Executa testes automatizados
- Conta acertos (`1`) e erros (`0`)
- Calcula nota de 0 a 10
- Gera CSV consolidado
- Não interrompe a execução em caso de erro de um aluno

---

## ▶️ Como executar

Entre na pasta `scripts`:

cd scripts

Dê permissão de execução (apenas uma vez):

chmod +x corrigir.sh

---

## 🧾 Opções de linha de comando

### Clonar repositórios
./corrigir.sh -c
./corrigir.sh -clone

### Corrigir sem clonar (usa repositórios existentes)
./corrigir.sh

### Corrigir apenas um aluno
./corrigir.sh -a Renato
./corrigir.sh -aluno Renato

### Corrigir apenas Trabalho 1
./corrigir.sh -t1

### Corrigir apenas Trabalho 2
./corrigir.sh -t2

### Combinações válidas
./corrigir.sh -c -t1
./corrigir.sh -t2 -a Leticia
./corrigir.sh -c -a Renato

---

## 📊 Arquivo de saída

O resultado é salvo em:

scripts/resultados/notas.csv

Exemplo de colunas:

aluno,
t1_acertos,t1_erros,t1_nota,t1_obs,
t2_acertos,t2_erros,t2_nota,t2_obs,
nota_final

- A **nota final** é a média aritmética dos trabalhos corrigidos
- O arquivo CSV é **sempre sobrescrito** a cada execução

---

## 🚨 Tratamento de erros

O script detecta e registra:

- Pasta do trabalho inexistente
- Arquivos `.c` ou `.h` ausentes
- Erro de compilação
- Erro de execução
- Timeout (se disponível no sistema)

Essas situações aparecem na coluna **observação** do CSV.

---

## 🧩 Extensões futuras

O script foi escrito para facilitar:

- Inclusão de Trabalho 3, 4, etc.
- Pesos diferentes por trabalho
- Nota mínima por atividade
- Relatórios individuais por aluno
- Execução paralela

---

## 🧑‍🏫 Público-alvo

- Professores
- Monitores
- Disciplinas introdutórias de Programação em C
- Turmas grandes com correção automatizada

---

## ✅ Conclusão

Este script fornece uma solução **robusta, reutilizável e extensível** para correção automática de trabalhos em C, com foco em **produtividade, clareza e confiabilidade**.