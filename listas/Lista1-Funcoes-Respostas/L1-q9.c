#include <stdio.h>


typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int id; 
    char nome[51];
    char sexo;
    char cpf[15];
    Data nascimento;
} Cliente;

int matricula = 0;
int geraNovaMatricula();

int validaSexo(char c);
Cliente cadastraCliente();

int main(){
	Cliente cli;

	cli = cadastraCliente();

	if (cli.id == -1){
		printf("Erro no cadastro. Verifique seus dados\n");
	}else {
		printf("Cliente cadastrado com sucesso\n");
	}
}

Cliente cadastraCliente(){
	Cliente meuCli;
	meuCli.id = -1;
	printf("Digite o sexo\n");
	char sexo;
	scanf("%c", &sexo);

	if (validaSexo(sexo) == 0){
		return meuCli;
	}else{
		//tratando os outros dados


	}

	meuCli.id = geraNovaMatricula();
	return meuCli;
}


//retorn 1 se sexo valido, e 0 se sexo inválido
int validaSexo(char c){
	char sexosValidos[] = {'M', 'F', 'm', 'f'};
	int qtdSexosValidos = 4;
	int i = 0;
	for (; i < qtdSexosValidos; i++){
		if (sexosValidos[i] == c){
			return 1;
		}
	}
	return 0;
}


int geraNovaMatricula(){

	return matricula++;
}


