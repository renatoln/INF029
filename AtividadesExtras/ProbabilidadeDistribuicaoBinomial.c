/*

Probabilidade de Distribuição Binomial.c, 18/07/2018, Autor: Renato Novais

*/

#include <stdio.h>

//calcula o exponencial de k elevado a y
float exponencial(float k, float y){
  int i;
  float exp = k;
  for (i = 1; i < y; i++){
    exp *= k;
  }
  return exp;
}

int fatorial(int n){
  int i;
  int fat = 1;
  for (i = 2; i <=n; i++){
    fat *= i;
  }
  return fat;
}

float probabilidadeDistribuicaoBinomial(int x, float p, int n){
  float n_x, prob;

  n_x = fatorial(n)/(fatorial(x)*fatorial(n-x));

  prob = n_x * exponencial(p, x) * exponencial(1-p, n-x);

  return prob;

}

int main(void)
{
  int x, n;
  float resultado, p;

  printf("Digite o total (x) de sucesso esperado do experimento: ");
  scanf("%d", &x);

  printf("Digite a probabilidade (p) de sucesso: ");
  scanf("%f", &p);

  printf("Digite o número (n) de experimentos: ");
  scanf("%d", &n);

  resultado = probabilidadeDistribuicaoBinomial(x, p, n);

  printf("A probabilidade de Distribuição binomial é: %f", resultado);

  return 1;

}
