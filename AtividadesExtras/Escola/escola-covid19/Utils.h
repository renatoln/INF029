typedef struct dma {
	char dataCompleta[11];
  	int dia;
  	int mes;
	int ano; 
} Data; 


int validar_data(char data[]);
int valida_data_numeros(int dia, int mes, int ano);