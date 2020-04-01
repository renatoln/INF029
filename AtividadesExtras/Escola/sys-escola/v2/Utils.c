#include <string.h>
#include <stdlib.h>

int verifica_numero(char CARACTER);
int verifica_ano_bisexto(int iAno);
int valida_numeros(int iDia, int iMes, int iAno);

int validar_data(char *data)
{
    int iDia;
    int iMes;
    int iAno;
    int retorno;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int iCont;
    int jCont;
    int verificacao;
    
    //CONVERTE DIA******************************************************************************
    for (iCont = 0; data[iCont] != '/'; iCont++)
    {
        sDia[iCont] = data[iCont];
        if(iCont >= 3)
            return 0;
    }

    sDia[iCont] = '\0';
    
    for (jCont = 0; sDia[jCont] != '\0'; jCont++)
    {
        verificacao = verifica_numero(sDia[jCont]);
        if(verificacao == 0)
            return 0;
    }
    
    if (strlen(sDia) == 0)
        return 0;
 
    iDia = atoi(sDia); 
 
    // CONVERTE MES*****************************************************************************
    for (iCont = iCont+1, jCont = 0; data[iCont] != '/'; iCont++, jCont++)
    {
        sMes[jCont] = data[iCont];
        if(jCont >= 3)
            return 0;
    }
    
    sMes[jCont] = '\0';
    
    for (jCont = 0; sMes[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sMes[jCont]);
            if(verificacao == 0)
                return 0;
    }
    
    if (strlen(sMes) == 0)
        return 0;
    
    iMes = atoi(sMes); 
  
    // CONVERTE ANO****************************************************************************
    
    for (iCont = iCont+1, jCont=0; data[iCont] != '\0' ; iCont++, jCont++)
    {
        sAno[jCont] = data[iCont];
    }
    sAno[jCont] = '\0';
    
    for (jCont = 0; sAno[jCont] != '\0'; jCont++)
    {
        verificacao= verifica_numero(sAno[jCont]);
        if(verificacao == 0)
            return 0;
    }
        
    if (strlen(sAno) == 0)
        return 0;
    
    iAno = atoi(sAno); 
 
    // *****************************************************************************************
    retorno= valida_numeros(iDia, iMes, iAno);
    
    return retorno;
}

int valida_numeros(int iDia, int iMes, int iAno)
{
    
    int bissexto = verifica_ano_bisexto(iAno);
    
    if (iDia < 1 || iDia > 31)
        return 0;
    
    else if (iDia >= 31 && (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11 ))
        return 0;
    
    else if (iMes < 1 || iMes > 12)
        return 0;
    
    else if(iDia> 29 && iMes == 2 && bissexto == 1)
        return 0;
    
    else if(iDia> 28 && iMes == 2 && bissexto == 0)
        return 0;
    
    else if (iAno <= 0)
        return 0;
    
  return 1;  
}

int verifica_ano_bisexto(int iAno)
{
    if(((iAno%4) == 0) && ((iAno%100) != 0) && ((iAno%400) != 0))
        return 1;
    return 0;
}

int verifica_numero(char CARACTER)
{
    if  (CARACTER < '0' && CARACTER > '9' )
        return 0;
    
    return 1;
}

