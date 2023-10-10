/*
* Lista dinâmica duplamente encadeada com nó cabeça e circularidade
* (Lista ligada dinâmica: 2 ponteiros prox e ant)
*
* Amanda Araujo Silva
*/

/* Tarefas:
(1) Inicialização (encadeamento duplo, circular e com nó cabeça)
(2) Ultimo elemento da lista (encadeamento duplo, circular e com nó cabeça) 
(3) Inserção ordenada sem duplicações
 */

#include <stdio.h>
#include <malloc.h>

// Definição da estrutura
typedef struct estrutura {
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct {
    NO *cabeca;
} LISTA_LIGADA_CABECA_CIRCULAR_DUPLA;

#define false 0
#define true 1
typedef int bool;

// Funções de gerenciamneto
// * Inicialização da lista
void inicializarLista(LISTA_LIGADA_CABECA_CIRCULAR_DUPLA *lista){
    // criar nó cabeça (alocar memória) & guardar endereço
    lista->cabeca = (NO*) malloc(sizeof(NO));
    // ajuste ponteiros: circular
    lista->cabeca->prox = lista->cabeca;
    lista->cabeca->ant = lista->cabeca;
}

// * Último elemento da lista
int ultimoElemLista(LISTA_LIGADA_CABECA_CIRCULAR_DUPLA *lista){
    // lista pode ser percorrida dos dois lados!
    // cuidado: nó cabeça não é válido
    if (lista->cabeca->ant == lista->cabeca) return -1; // não há nós válidos 
    return lista->cabeca->ant->chave;
}

// * Busca sequencial: posição elem e ant
NO* buscaSeqOrd(LISTA_LIGADA_CABECA_CIRCULAR_DUPLA *lista, int ch, NO* *ant){
    NO* end = lista->cabeca->prox;
    *ant = lista->cabeca;    // salva antecessor
    // nó cabeça: sentinela
    lista->cabeca->chave = ch;
    while (end->chave < ch){
        *ant = end;
        end = end->prox;
    } 
    // saída: encontrou de fato se ch= e endereço != sentinela (cabeca)
    if ((end->chave == ch) && (end != lista->cabeca)) return end;
    return NULL;
}

// * Inserção ordenada sem duplicações
bool inserirElemOrd(LISTA_LIGADA_CABECA_CIRCULAR_DUPLA *lista, int ch){
    // buscar elemento
    NO *ant, *i;
    i = buscaSeqOrd(lista, ch, &ant); 
    if (i != NULL) return false; // elem já presente, duplicata
    // inserir
    i = (NO*) malloc(sizeof(NO)); // alocar memória novo elem
    i->chave = ch;                // valor nó novo
    // ajuste dos ponteiros (4 ponteiros): temos endereço antecessor do novo elem
    i->prox = ant->prox;
    i->ant = ant;
    i->prox->ant = i;
    ant->prox = i;
    return true;
}

// * Exibição da lista
void exibirLista(LISTA_LIGADA_CABECA_CIRCULAR_DUPLA *lista){
    NO *end = lista->cabeca->prox; // 1º nó válido
    while (end != lista->cabeca){
        printf("%d ", end->chave);
        end = end->prox;
    }
    printf("\n");
}

int main(){
    
    // Declarar lista
    LISTA_LIGADA_CABECA_CIRCULAR_DUPLA lista;
    NO *ant;

    // Inicialização
    inicializarLista(&lista);

    // Inserir elementos
    inserirElemOrd(&lista, 1);
    exibirLista(&lista);
    inserirElemOrd(&lista, 3);
    exibirLista(&lista);
    inserirElemOrd(&lista, 7);
    exibirLista(&lista);
    inserirElemOrd(&lista, 2);
    exibirLista(&lista);


    return 0;
}
