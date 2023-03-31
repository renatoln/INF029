#include <stdio.h>
#include <string.h>

typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

int quebraData(char *data);

int main(){
	char str[11];
    //teste 1
    strcpy(str, "19/02/2015");
    int retorno = quebraData(str);
    printf("Retorno: %d\n", retorno);
    //teste 2
    strcpy(str, "9/2/2015");
    retorno = quebraData(str);
    printf("Retorno: %d\n", retorno);
    //teste 3
    strcpy(str, "/02/2015");
    retorno = quebraData(str);
    printf("Retorno: %d\n", retorno);
	//teste 4
    strcpy(str, "19//2015");
    retorno = quebraData(str);
    printf("Retorno: %d\n", retorno);
    //teste 5
    strcpy(str, "19/2/2");
    retorno = quebraData(str);
    printf("Retorno: %d\n", retorno);
	return 0;
}

//quebrar a string data em strings sDia, sMes, sAno
//retorna 1 se tiver tudo certo
//retorna 0 se deu algum erro
int quebraData(char *data){

	char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else 
		return 0;
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		return 0;
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		return 0;
	

	//imprimir os valores apenas para teste
	printf("---------------");
	printf("Data: %s\n", data);	
	printf("Dia: %s\n", sDia);
	printf("Mes: %s\n", sMes);
	printf("Ano: %s\n", sAno);

	return 1; 
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}