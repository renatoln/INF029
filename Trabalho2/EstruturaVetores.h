#define SUCESSO 1
#define SEM_ESPACO 2
#define SEM_ESTRUTURA_AUXILIAR 3
#define JA_TEM_ESTRUTURA_AUXILIAR 4
#define POSICAO_INVALIDA 5
#define SEM_ESPACO_DE_MEMORIA 6
#define TAMANHO_INVALIDO 7

int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int listaEstruturaAuxiliar(int posicao);
void dobrar(int *x);
