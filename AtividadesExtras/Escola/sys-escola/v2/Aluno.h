
/*Criando a struct aluno */
typedef struct dados_aluno
{
  int matricula;
  char nome[50];
  char sexo; //M - Masculino, F - Feminino
  Data data_nascimento;
  char cpf[15];
  struct dados_aluno *prox;
    
} Aluno;

void mainAluno(Aluno** inicio);
int menuAluno();
int inserirAluno(Aluno** inicio);
void listarAlunos(Aluno** inicio);
void liberarLista(Aluno* inicio); //v2
//v2
int valida_numeros(int iDia, int iMes, int iAno);
int verifica_ano_bisexto(int iAno);
int verifica_numero(char CARACTER);
