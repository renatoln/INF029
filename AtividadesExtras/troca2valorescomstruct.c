#include <stdio.h>
//vetores
//struct
//ponteiros



typedef struct t{
    int x;
    int y;
} Numeros;

Numeros troca(int a, int b);

int main(){
    Numeros num;
    
    num.x = 2;
    num.y = 3;
    
    num = troca(num.x, num.y);
    
    printf("%d %d", num.x, num.y);
    
    return 0;
}

Numeros troca(int a, int b){ 
    int aux = a;
    a = b; 
    b = aux;
    Numeros n;
    n.x = a;
    n.y = b;
    return n;
}
