#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11

typedef struct vetor
{
	int tam;
	int *vetorAux;
	int posicaoAtual;
	int posicaoPrint;

}cell;

cell vetorPrincipal[10];

void iniciarPrincipal(cell vetorPrincipal[]);
int criarEstruturaAuxiliar(int tamanho, int posicao, int valor);
int inserirNumeroEmEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
void liberarEspacosEstruturasAuxiliares();
void dobrar(int *x);
int receberValor();
void imprimirEstruturaAux(int posicao,cell vetorPrincipal[]);
void swift(cell vetorPrincipal[], int indicePrincipal, int posAtual, int tamTotal, int valor);
