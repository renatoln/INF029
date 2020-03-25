typedef struct dma {
  int dia;
  int mes;
  int ano; 
} Data; 



int validar_data(char data[]){
    
    
    int dia;
    int mes;
    int ano;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];
    
    // data = "/02/2019"
    
    int i;
    //converter
    for (i = 0; data[i] != '/' && i < 2; i++){
        sDia[i] = data[i];
        
        
    }
    sDia[i] = '\0';
    

    
    //usar o atoi ou algo do tipo dia = "03" - '0';
    iDia = atoi(sDia); //sDia - '0';
    
    
    
    //validar
    int retorno = valida_data_numeros(dia, mes, ano);
    
    return retorno;
    
    
    
}

int valida_data_numeros(int dia, int mes, int ano){
    
    if (dia < 1 || dia > 31)
        return 0;
    
    if (mes < 1 || mes > 12)
        return 0;
    
    if (ano <= 0)
        return 0;
    
    
}
