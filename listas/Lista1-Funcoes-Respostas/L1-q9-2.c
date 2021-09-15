#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}datanascimento;

/*
Erros 
-1 - erro no nome
-2 - erro no cpf
-3 - erro no sexo
-4 - erro na datanascimento


*/

typedef struct {
    int id;
    char nome[20];
    char cpf[11]; 
    char genero; 
    datanascimento datanasc;
    int nomevalidado;
    int generovalidado;
    int cpfvalidado;
    int nascimentovalidado;
}cadastroCliente;

cadastroCliente cadastrarcliente ();

int validarNome(char string[]);
int validarGenero(char c);
int validarCPF();
int validarNascimento();
int ehBissexto(int ano);


int main(){
    cadastroCliente cliente;
    cliente = cadastrarcliente();
    
    if (cliente.id <= 0){ 
        
        if (cliente.id == -1){
            printf("ERRO no cadastro do nome");    
        }else if (cliente.id == -2){
            printf("ERRO no cadastro do cpf");    
        }

    }else{
        printf("\n\n*************************************\n\n");
        printf("Cliente cadastrado com sucesso:\n");
        printf("%s\n",cliente.nome);
        printf("%s\n",cliente.cpf);
        printf("%d/%d/%d\n", cliente.datanasc.dia,cliente.datanasc.mes,cliente.datanasc.ano);
    }    
    
    system("PAUSE");
}

cadastroCliente cadastrarcliente () {
    cadastroCliente entrada_dados;
    entrada_dados.id = -1;
    printf("Favor inserir o nome do cliente:\n");
    gets(entrada_dados.nome);
    int erro = validarNome(entrada_dados.nome);
    if (erro == 1)
        entrada_dados.id = -1;
        return entrada_dados;
    else{
        printf("Favor inserir o CPF do cliente. Não usar pontos ou hífens\n");
        gets(entrada_dados.cpf);
        erro = validarCPF(entrada_dados.cpf);
        
        if (erro == 1)
            entrada_dados.id = -2;
            return entrada_dados;
        else{
            printf("Favor inserir o gênero do cliente. Utilize M para gênero masculino, F para feminino e O para outro\n");
            scanf ("%c", &entrada_dados.genero);
            entrada_dados.generovalidado=validarGenero(entrada_dados.genero);
            printf("Favor inserir o dia do nascimento do cliente:\n");
            scanf("%d",&entrada_dados.datanasc.dia);
            printf("Favor inserir o mês do nascimento do cliente:\n");
            scanf("%d",&entrada_dados.datanasc.mes);
            printf("Favor inserir o ano do nascimento do cliente:\n");
            scanf("%d",&entrada_dados.datanasc.ano);    
        }

         
    }
    entrada_dados.id = 1;
    return entrada_dados;
}
    
int validarNome(char string[]){
    int numerocaracteres = 0;
    int erro = 0;
    while(string[numerocaracteres] != '\0'){
        numerocaracteres++;
    }
    if(numerocaracteres > 20){
        erro = 1;
    }

    return erro;
}

int validarGenero(char c){
    int generovalidado=0;
    if(c == 'f' || c == 'F' || 
       c == 'm' || c == 'M'){
        return 1;
    }
    else{
        return 0;
    }
}

int validarCPF(char string[]){
    int numeroscpf = 0;
    while(string[numeroscpf] != '\0'){
        numeroscpf++;
    }
    if(numeroscpf > 14){
        numeroscpf = 0;
    }
    else{
        numeroscpf = 1;
    }
    return numeroscpf;
}

// retorna 0 - inválida
// retorna 1 - valida
int validarNascimento(datanascimento data){
    
    if (data.dia < 1 || data.dia > 31)
        return 0;
    if (data.mes < 1 || data.mes > 12)
        return 0;
    if (data.ano > 2021)
        return 0;

    // meses de 30 dias
    if ((data.mes == 4 ||
        data.mes == 6 ||
        data.mes == 9 ||
        data.mes == 11) && data.dia > 30){

        return 0;
    } if (data.mes == 2){
        if (ehBissexto(data.ano) && data.dia > 29){
            return 0;
        }else if (data.dia > 28){
            return 0;
        }

    }

    return 1;
}

int ehBissexto(int ano){
    //To Do
    return 0;
}
