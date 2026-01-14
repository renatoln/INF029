# Script de Correção Automática de Trabalhos em C

Este repositório contém um **script de correção automática** para trabalhos em C
(Trabalho 1, Trabalho 2, e extensível para outros), com suporte a:

- clonagem automática de repositórios GitHub
- execução seletiva por trabalho
- execução seletiva por aluno
- tratamento de erros de compilação
- tratamento de segmentation fault
- penalidade configurável
- geração de notas em CSV
- ambiente reproduzível para correções oficiais

---

## 📂 Estrutura de Diretórios

A estrutura esperada do projeto é:

```

.
├── trabalho1
│   └── corretor-final.c
│
├── trabalho2
│   └── mainTeste.c
│
└── scripts
├── corrigir.sh
├── repos.txt
├── repos
└── resultados

```

### Descrição

- `trabalho1/`  
  Contém o corretor oficial do Trabalho 1.

- `trabalho2/`  
  Contém o corretor oficial do Trabalho 2.

- `scripts/corrigir.sh`  
  Script principal de correção.

- `scripts/repos.txt`  
  Arquivo com **uma URL de repositório Git por linha**.

- `scripts/repos/`  
  Diretório onde os repositórios dos alunos são clonados.

- `scripts/resultados/`  
  Diretório onde é gerado o arquivo `notas.csv`.

---

## 📥 Formato do arquivo `repos.txt`

Cada linha deve conter **uma URL válida de repositório Git**:

```

https://github.com/aluno1/INF029-NomeSobreNome.git
https://github.com/aluno2/INF029-NomeSobreNome.git

````

Linhas vazias ou iniciadas com `#` são ignoradas.

---

## ▶️ Como executar

Entre na pasta `scripts`:

```bash
cd scripts
````

Dê permissão de execução (uma única vez):

```bash
chmod +x corrigir.sh
```

---

## 🔧 Parâmetros disponíveis

### Clonar repositórios

```bash
./corrigir.sh -c
```

ou

```bash
./corrigir.sh -clone
```

---

### Corrigir apenas um aluno

```bash
./corrigir.sh -a INF029-BrunoAlves
```

ou

```bash
./corrigir.sh -aluno INF029-BrunoAlves
```

---

### Corrigir apenas um trabalho

```bash
./corrigir.sh -t1
./corrigir.sh -t2
```

---

### Corrigir ambos os trabalhos (padrão)

```bash
./corrigir.sh
```

---

### Limpar ambiente de correção

```bash
./corrigir.sh -clean
```

Este comando remove:

* repositórios clonados
* logs de clone
* arquivos de saída
* binários temporários

---

## 🧮 Cálculo da nota

A nota é calculada da seguinte forma:

1. O total de testes é obtido automaticamente lendo o corretor
2. Cada teste imprime `1` (sucesso) ou `0` (falha)
3. A nota bruta é:

```
(acertos / total_de_testes) * 10
```

4. Em caso de `segmentation fault`, é aplicada uma penalidade configurável

---

## ⚠️ Importante: segmentation fault e buffering

Quando um programa em C sofre `segmentation fault`, a saída padrão (`stdout`)
pode não ser descarregada corretamente se estiver bufferizada.

Para garantir que todos os testes executados sejam contabilizados, o script
utiliza:

```
stdbuf -oL ./exec
```

### Dependências

#### Linux (Ubuntu/Debian)

```bash
sudo apt install coreutils
```

#### macOS

```bash
brew install coreutils
```

---

## 📄 Arquivo de saída

O arquivo gerado é:

```
scripts/resultados/notas.csv
```

Formato:

```
aluno,
t1_acertos,t1_falhas,t1_nota,t1_obs,
t2_acertos,t2_falhas,t2_nota,t2_obs,
nota_final
```

---

## ✅ Observações finais

* Diretórios auxiliares (como logs de clone) são ignorados automaticamente
* O script é tolerante a erros de compilação e execução
* Pode ser facilmente estendido para Trabalhos 3, 4, etc.

---

## 👨‍🏫 Uso recomendado

Para uma correção oficial:

```bash
./corrigir.sh -clean -c
./corrigir.sh
```

Isso garante um ambiente limpo e resultados reproduzíveis.
