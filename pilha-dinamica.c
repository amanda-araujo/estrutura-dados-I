/*
* Filas - Implementação dinâmica
* (last-in, first-out: LIFO)
*
* Amanda Araujo Silva
*/

#include <stdio.h>
#include <malloc.h>

// Definição estrutura
typedef struct estrutura{
    int chave;
    struct estrutura prox*
} NO;

typedef struct {
    NO *topo;
} PILHA_DINAMICA;