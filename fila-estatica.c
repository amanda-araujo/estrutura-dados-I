/*
* Filas - Implementação estática
* (inserções no final, exclusões no início)
*
* Amanda Araujo Silva
*/

/* Tarefas:
(1) Inicializacao da fila estática
(2) Inserção de novo item ao final
(3) Retirada de um item da frente ou retornar -1 se vazia */

#include <stdio.h>

#define MAX 50

// Definição estrutura: Implementação estática - arranjo tam pré-def
typedef struct{
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio; // índice do começo da fila
    int nElem;  // números de elementos
} FILA_ESTATICA;

#define true 1
#define false 0
typedef int bool;

// Funções de gerenciamento
// * Inicialização da fila
void inicializarFilaEstat(FILA_ESTATICA *fila){
    fila->nElem = 0;  // fila vazia
    fila->inicio = 0; // convenção
}

// * Tamanho
int tamanhoFilaEstat(FILA_ESTATICA *fila){
    return fila->nElem;
}

// * Exibição da fila
void exibirFilaEstat(FILA_ESTATICA *fila){
    // iterar pelos elementos válidos
    // há nElem válidos
    int i = fila->inicio; // índice elem atual
    for (int j = 0; j < fila->nElem; j++){
        printf("%d ", fila->A[i].chave);
        i = (i + 1) % MAX; // cuidado p não estourar índice máximo (MAX - 1)
    }
    printf("\n");
}

// * Inserção elemento: final da fila
bool inserirElemFilaEstat(FILA_ESTATICA *fila, int ch){
    // verificar se tem espaço
    if (fila->nElem >= MAX) return false;
    // insere: na última
    // vericar em qual posição: do (último elem + 1) mod MAX - vetor giratório 
    int posicao = (fila->inicio + fila->nElem) % MAX;
    fila->A[posicao].chave = ch;
    fila->nElem++;
    return true;
}

// * Exclusão de elemento: primeiro elem, retorna ele para o usuário
bool excluirElemFilaEstat(FILA_ESTATICA *fila, int *reg){
    // tem que ser o primeiro elemento
    if (fila->nElem == 0) return false; // fila vazia
    *reg = fila->A[fila->inicio].chave;       // salva o valor do elemento retirado
    fila->inicio = (fila->inicio + 1) % MAX; // anda a fila 1 casa
    fila->nElem--; 
    return true;
    // não precisa se preocupar em 'apagar' o valor da entrada
}


int main(){

    // Declaração da fila
    FILA_ESTATICA fila;

    // Inicialização da fila 
    inicializarFilaEstat(&fila);

    // Inserir elementos na fila
    inserirElemFilaEstat(&fila, 10);
    exibirFilaEstat(&fila);
    inserirElemFilaEstat(&fila, 8);
    exibirFilaEstat(&fila);
    inserirElemFilaEstat(&fila, 5);
    exibirFilaEstat(&fila);

    // Exclusão de elementos
    int reg;  // salva valor retirado da fila (1º da fila)
    excluirElemFilaEstat(&fila, &reg);
    printf("Elemento retirado (1º da fila): %d\n", reg);
    exibirFilaEstat(&fila);

    return 0;
}