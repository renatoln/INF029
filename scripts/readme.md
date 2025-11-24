# Script de correção dos trabalhos
Shell Script para corrigir trabalhos automaticamente.

## Para rodar
1. adicine as urls dos repositórios, um por linha, no arquivo scripts/repos.txt
2. execute o comando de execução do script shell

> ./corrigir.sh -clone
- faz o clone dos repositórios, 
- salva em uma pasta repos, 
- compila, 
- executa, 
- gera saídas de erro em um arquivo de logs
- gera uma pasta resultados com as notas

> ./corrigir.sh 
- roda o script sem fazer o clone

> ./corrigir.sh -nome INF029-JoaoSilva
- corrige apenas o trabalho de INF029-JoaoSilva. Essa pasta deve existir na pasta repos.