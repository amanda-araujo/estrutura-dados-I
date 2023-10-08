/*
* Lista ligada estática
* (ordem lógica != ordem física)
*
* Amanda Araujo Silva
*/

/* Tarefas:
(1) Exibição da lista ligada de implementação estática completa
(2) Busca sequencial, retornando a posição da chave e do anterior
(3) Obtenção do nó disponível - a lista é alterada
(4) Exclusão do elemento de chave indicada
(5) Inserção em lista ordenada sem duplicações
 */

#include <stdio.h>

// Definição da estrutura
#define MAX 50

typedef struct{ // NÓ
    int chave;  // Valor do nó
    int prox;   // Sucessor do nó
} REGISTRO;

typedef struct{ // LISTA
    REGISTRO A[MAX]; // Vetor de nós
    int inicio;      // Indica primeiro nó efetivo (ocupado)
    int dispo;       // Início posições livres 
} LISTA_LIGADA_ESTATICA;

#define false 0
#define true 1
typedef int bool;

// Protótipos funções de gerenciamento 
void inicializarListaLigEstat(LISTA_LIGADA_ESTATICA *lista);
void exibirListaLigEstat(LISTA_LIGADA_ESTATICA lista);                            // (1)
bool insercaoElemUltimoListaLigEstat(LISTA_LIGADA_ESTATICA *lista, int ch);
bool buscaSequencialListaLigEstat(LISTA_LIGADA_ESTATICA lista, int ch, int *ant); // (2)
int buscaSeqOrdListaLigEstat (LISTA_LIGADA_ESTATICA lista, int ch, int *ant);
//bool insercaoOrdenadaListaLigEstat(LISTA_LIGADA_ESTATICA *lista, int ch);
bool insercaoElemOrdListaLigEst (LISTA_LIGADA_ESTATICA *lista, int ch);
int obterNoListaLigEstat (LISTA_LIGADA_ESTATICA *lista);


int main(){

    // Declaração lista do tipo lista ligada estática
    LISTA_LIGADA_ESTATICA lista;
    int ant;

    // Inicialização: lista vazia
    inicializarListaLigEstat(&lista); // passagem por referência

    // Adição de elementos na lista: 
    for (int i = 0; i < 10; i++){
        //insercaoElemUltimoListaLigEstat(&lista, i*10);
        insercaoElemOrdListaLigEst(&lista, i*10);
    }

    // Exibição da lista
    exibirListaLigEstat(lista); // passagem por valor (cópia)
    return 0;

    insercaoElemUltimoListaLigEstat(&lista, 100);
    exibirListaLigEstat(lista);
    printf("Valor do campo dispo: %d\n", lista.dispo);
    printf("Quantidade de espaços disponíveis na lista: %d\n", (MAX - lista.dispo));

    // Busca sequencial por um elemento
    buscaSequencialListaLigEstat(lista, 0, &ant);
    buscaSequencialListaLigEstat(lista, 20, &ant);
    buscaSequencialListaLigEstat(lista, 15, &ant);
    buscaSequencialListaLigEstat(lista, 100, &ant);

    // Busca sequencial ordenada
    int posicao = buscaSeqOrdListaLigEstat (lista, 100, &ant);
    printf("%d\n", posicao);

    // Inserção ordenada
    insercaoElemOrdListaLigEst(&lista, 5);
    exibirListaLigEstat(lista);
    insercaoElemOrdListaLigEst(&lista, 6);
    exibirListaLigEstat(lista);
    insercaoElemOrdListaLigEst(&lista, 10);
    exibirListaLigEstat(lista);

    return 0;
}

// Funções de gerenciamneto
// * Inicialização da lista 
void inicializarListaLigEstat(LISTA_LIGADA_ESTATICA *lista){
    // Criar lista vazia: preencher todos os seus campos (3)
    lista -> inicio = -1;
    lista -> dispo = 0;

    // Campos do vetor de registro: chave = vazia, prox = posição sucessora
    for (int i = 0; i < MAX - 1; i++){
        lista -> A[i].prox = i + 1; // encadeando a lista 
    } 
    lista -> A[MAX - 1].prox = -1; // último elemento não tem sucessor
};

// * Exibição da lista
void exibirListaLigEstat(LISTA_LIGADA_ESTATICA lista){
    // Percorrer toda a lista
    if (lista.inicio == -1){
        printf("A lista está vazia");
    }
    /* else{
        printf("Lista: ");
        for (int i = lista.inicio; i < lista.dispo; i++){
            printf("%d ", lista.A[i].chave);
        }
        printf("\n");
    } */ 
    else{
        int i = lista.inicio;
        while (i > -1){
            printf("%d", lista.A[i].chave);
            i = lista.A[i].prox;
        }
    }
};

// * Inserção de elemento na lista (última posição)
bool insercaoElemUltimoListaLigEstat(LISTA_LIGADA_ESTATICA *lista, int ch){ // passagem por referência
    // Checar se a lista não está cheia
    if (lista -> dispo == -1){
        printf("A lista está cheia\n");
        return false;
    }
    else{
        // checar se é o primeiro elemento
        if (lista -> inicio == -1){
            lista -> inicio = 0;
        }
        // inserção sempre na primeira posição disponível
        lista -> A[(lista -> dispo)].chave = ch; // Inserido novo valor
        lista -> dispo++;

        return true;
    }
}

// * Busca sequencial de um elemento: retornando a posição da chave e do anterior
// Equívoco: aqui n retorna posição da chave em uma variável! Apenas como texto, logo não é útil!!! 
bool buscaSequencialListaLigEstat(LISTA_LIGADA_ESTATICA lista, int ch, int *ant){ //múltiplos retornos: uso de ponteiros
    if (lista.inicio == -1){
        printf("A lista está vazia, o elemento não se encontra na lista\n");
        return false;
    }
    else{ // procure: percorra a lista elemento por elemento
        for (int i = 0; i < lista.dispo; i++){
            if(lista.A[i].chave == ch){ // encontrou
                *ant = i - 1;
                printf("Elemento %d encontrado na posição %d (posição do anterior: %d)\n", ch, i, *ant);
                return true;
                break;
            }
            if(i == (lista.dispo - 1)){ // foi até o último elem e não encontrou
                printf("Elemento %d não encontrado na lista\n", ch);
                return false;
            }
        }
    }
}

// * Busca Sequencial Ordenada
int buscaSeqOrdListaLigEstat (LISTA_LIGADA_ESTATICA lista, int ch, int *ant){
    // retorna posição do elemento procurado (ausente: -1)
    int i = lista.inicio;
    *ant = -1;
    while (i != -1){ // true: percorre toda a lista
        if (lista.A[i].chave >= ch){ 
            break;
        }
        *ant = i;
        i = lista.A[i].prox;
    }
    // analisando condição de parada
    // se a ch for maior: n está presente (lista ordenada)
    // se ch ==: presente
    if ((i != -1) && (lista.A[i].chave == ch)){ // presente
        return i; 
    }
    else{ // ausente
        return (-1);
    }
}

// * Inserção de elemento de forma ordenada (Tentativa 2)
bool insercaoElemOrdListaLigEst (LISTA_LIGADA_ESTATICA *lista, int ch){
    
    // condições de não inserção: false
    int ant, i;
    i = buscaSeqOrdListaLigEstat(*lista, ch, &ant); // posicao do elem e do anterior na lista

    if (lista -> dispo == -1){
        printf("A lista está cheia! Não é possível inserir elemento.\n");
        return false;
    }

    if (i != -1){
        printf("O elemento já consta na lista. Não é possível inserir elemento duplicado.\n");
        return false;
    }

    // inserção: true
    // 1 - atribuir um nó ao valor a ser inserido
    i = obterNoListaLigEstat(lista);  // posição novo nó
    lista -> A[i].chave = ch;          // chave novo nó

    // 2 - realizar ligações ponteiros para manter a ordem lógica
    if (lista -> inicio == -1){
        // inserção em lista vazia
        lista -> inicio = i;
    }
    else{
        if (ant == -1){
            // inserção no 1º elemento da lista
            lista -> A[i].prox = lista -> inicio;
            lista -> inicio = i;
        }     
        else{
            // inserção entre 2 elementos
            lista -> A[i].prox = lista -> A[ant].prox;
            lista -> A[ant].prox = i;
        }
    }
    return true;
}

// * Obter nó disponível (para preencher com um novo valor na lista)
// retorna: posição do novo nó
int obterNoListaLigEstat (LISTA_LIGADA_ESTATICA *lista){
    int novo = lista -> dispo;
    if (lista -> dispo > -1){ // há espaço 
        lista -> dispo = lista -> A[(lista -> dispo)].prox;
    }
    return novo;
}
