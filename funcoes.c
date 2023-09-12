#include <stdio.h>

// Passagem de parâmetros de funções por valor e por referência

// Protótipos das funções de apoio
void soma(int a);     // Passagem por valor
void somaref(int *a); // Passagem por referência

int main(void)
{
  int numero;
  printf("Digite um numero: ");
  scanf("%d", &numero);  
     
  printf("O numero digitado: %d \n", numero);
  
  soma(numero);  //chamada da função 
  printf("Agora o numero vale (por valor): %d \n", numero); 
  
  somaref(&numero);  //chamada da função com ponteiro como parâmetro 
  printf("Agora o numero vale (por referência): %d \n", numero); 
  return 0;
}

// Passagem por valor
void soma(int a)
{
    a = a + 10;
    printf("Soma por valor: %d\n", a);
}

// Passagem por referência
void somaref(int *a)
{
    *a = *a + 10;
    printf("Soma por referência: %d\n", *a);
}