/*
* Filas - Implementação dinâmica
* (inserções no final, exclusões no início)
*
* Amanda Araujo Silva
*/

/* Tarefas:
(1) Inicializa¸c˜ao da fila dinˆamica
(2) Quantos elementos existem?
(3) Inser¸c˜ao de item ao final da fila dinˆamica
(4) Retirada da chave da frente ou -1
 */

#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} NO;

typedef struct {
    NO *inicio; // útil para exclusão
    NO *fim;    // útil para inserção
} FILA_DINAMICA;

#define true 1
#define false 0
typedef int bool;

// Funções de gerenciamento
// * Inicialização
void inicializarFilaDinam(FILA_DINAMICA *fila){
    // fila vazia
    // acertar valores de *inicio e *fim
    fila->inicio = NULL;
    fila->fim = NULL;
}

// * Tamanho
int tamanhoFilaDinam(FILA_DINAMICA *fila){
    // percorrer os elementos da fila
    // não circular: ultimo -> NULL
    NO *end = fila->inicio;
    int tam = 0;
    while (end != NULL){
        tam++;
        end = end->prox;
    } 
    return tam;
}

// * Exibição
void exibirFilaDinam(FILA_DINAMICA *fila){
    // percorrer os elementos da fila
    // não circular: ultimo -> NULL
    NO *end = fila->inicio;
    while (end != NULL){
        printf("%d ", end->chave);
        end = end->prox;
    }
    printf("\n");
}

// * Inserção elemento: sempre no final da fila
bool inserirElemFilaDinam(FILA_DINAMICA *fila, int ch){
    // alocação dinam: sempre tem espaço
    NO *i;
    i = (NO*) malloc(sizeof(NO));
    i->chave = ch;
    // ajuste ponteiro
    i->prox = NULL;
    // teste fila vazia
    if(fila->inicio == NULL) fila->inicio = i; // único elem da fila
    else fila->fim->prox = i;
    fila->fim = i;
    return true;
}

// * Exclusão elemento: sempre o primeiro (inicio)
bool excluirElemFilaDinam(FILA_DINAMICA *fila, int *reg){
    // se a fila não estiver vazia
    if (fila->inicio == NULL) return false; // fila vazia
    *reg = fila->inicio->chave;  // salva o valor de saída (primeiro elem fila)
    // liberar a memória
    NO *apagar = fila->inicio;
    fila->inicio = fila->inicio->prox;
    free(apagar);
    // teste fila vazia após exclusão do elem
    if (fila->inicio == NULL) fila->fim = NULL;
    return true;
}

int main(){

    FILA_DINAMICA fila;
    inicializarFilaDinam(&fila);

    inserirElemFilaDinam(&fila, 2);
    exibirFilaDinam(&fila);
    inserirElemFilaDinam(&fila, 4);
    exibirFilaDinam(&fila);
    inserirElemFilaDinam(&fila, 5);
    exibirFilaDinam(&fila);
    inserirElemFilaDinam(&fila, 31);
    exibirFilaDinam(&fila);

    printf("Tamanho fila: %d\n", tamanhoFilaDinam(&fila));

    int reg;
    excluirElemFilaDinam(&fila, &reg);
    exibirFilaDinam(&fila);
    
    printf("Tamanho fila: %d\n", tamanhoFilaDinam(&fila));

    return 0;
}
