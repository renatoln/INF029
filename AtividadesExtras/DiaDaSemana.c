#include <stdio.h> 
#include <stdlib.h> 

int calculaDia(int data);
int calculaCodigoAno(int ano);
int calculaCodigoMes(int mes);
int calculaCodigoSeculo(int ano);
int calculaNumeroData(int data);
int calculaAnoBissexto(int data);
void imprimeDiaExtenso(int numeroDia);




/*Programa para poder calcular o dia da semana a partir de uma data*/
int recuperaDoisDigitosAno(int ano){
    /* ToDo implementar*/
    return ano;
    
}

int calculaCodigoAno(int ano){
    int anoDoisDigitos = recuperaDoisDigitosAno(ano);    
    //(YY + (YY div 4)) mod 7
    int resultado = (anoDoisDigitos +
                    (anoDoisDigitos / 4)) % 7;
    return resultado;
}

//funcao retorna -1 se o mês foi Inválido
int calculaCodigoMes(int mes){
    
    switch(mes){
        
        case 1: return 0;
        case 2: return 3;
        case 3: return 3;
        case 4: return 6;
        case 5: return 1;
        case 6: return 4;
        case 7: return 6;
        case 8: return 2;
        case 9: return 5;
        case 10: return 0;
        case 11: return 3;
        case 12: return 5;
        default: return -1;
    }
    
}
//implementado apenas para datas Gregorianas
int calculaCodigoSeculo(int ano){
    
    if (ano >= 1752 && ano < 1800)
        return 4;
    else if (ano >= 1800 && ano < 1900)
        return 2;
    else if (ano >= 1900 && ano < 2000)
        return 0;
    else if (ano >= 2000 && ano < 2100)
        return 6;
    /* ToDo - a partir daqui a cada 4 seculos os codigos se repetem,
    melhorar código apra resolver isso de forma automática 
    */
    else if (ano >= 2100 && ano < 2200)
        return 4;
    else if (ano >= 2200 && ano < 2300)
        return 2;
    else if (ano >= 2300 && ano < 2400)
        return 0;
    else if (ano >= 2400 && ano < 2500)
        return 6;
    
}

//retorna o dia
int calculaNumeroData(int data){
    int dia = 24; //implementar
    return dia;
}

int ehBissexto(int ano){
    
    if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) 
        return 1;
    else 
        return 0;
}

int calculaAnoBissexto(int data){
    //se data janeiro ou feveiro de ano bissexto retorna 1, caso contrário retorne 0
    
    int mes = 2; //recuperar mes da data
    int ano = 2018;
    
    if ((mes == 1 || mes == 2) &&
        ehBissexto(ano))
        return 1;
    else
        return 0;
}

int calculaDia(int data){
    int ano = 2018;
    int ano_Dois_Digitos = 18; //variavel temporia so para testar
    int mes = 2;
    //(Year Code + Month Code + Century Code + Date Number – Leap Year Code) mod 7
    int resultado = (           calculaCodigoAno(ano_Dois_Digitos) +
                    calculaCodigoMes(mes) +
                    calculaCodigoSeculo(ano) +
                    calculaNumeroData(data) -
                    calculaAnoBissexto(ano)) % 7; 
                    
    return resultado;
    
}


void imprimeDiaExtenso(int numeroDia){
    
    switch(numeroDia){
        case 0: printf("Domingo"); break;
        case 1: printf("Segunda"); break;
        case 2: printf("Terça"); break;
        case 3: printf("Quarta"); break;
        case 4: printf("Quinta"); break;
        case 5: printf("Sexta"); break;
        case 6: printf("Sábado"); break;
        default: printf("Dia Inválido");
    }
    
    
}

int main(){
    
   /*imprimeDia(4); 
   imprimeDia(6);
   imprimeDia(9);*/
   //6 de 10 de 2088 
   int i = calculaDia(20881006);
   
   imprimeDiaExtenso(i);
   
    
}

