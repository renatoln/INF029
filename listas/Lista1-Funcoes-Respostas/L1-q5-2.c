#include <stdio.h>
#define tam 4

typedef struct{
    int a[tam];
} num;


num ler4Numeros(){
    num n;
    int i;

    for(i=0; i<tam; i++){
        scanf("%d", &n.a[i]);
        
    }

    return n;

}

int main(){

    num n1;
    int i;
    printf("Digite os numeros a serem impressos");
    
    n1 = ler4Numeros();

    printf("Os numeros digitados sao: %d, %d, %d e %d\n", n1[0].a, n1[1].a, n1[2].a, n1[3].a);
}
