#include <stdio.h>

int ehTriangulo(int x, int y, int z){
    if ((x < y + z) && (y < x + z) && (z < x + y)){
        return 1;
    }
    return 0;
}

void verifica4varetas(int varetas[4], int vetor[3]){
    
    if (ehTriangulo(varetas[0], varetas[1], varetas[2])){
        vetor[0] = varetas[0];
        vetor[1] = varetas[1];
        vetor[2] = varetas[2];
    }else if (ehTriangulo(varetas[0], varetas[1], varetas[3])){
        vetor[0] = varetas[0];
        vetor[1] = varetas[1];
        vetor[2] = varetas[3];       
    }else if (ehTriangulo(varetas[0], varetas[2], varetas[3])){
        
    }else if (ehTriangulo(varetas[1], varetas[2], varetas[3])){
        
    }

}