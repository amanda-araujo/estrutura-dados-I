/*
* Lista ligada dinâmica
* (ordem lógica != ordem física)
*
* Amanda Araujo Silva
*/

/* Tarefas:
(1) Exibicao da lista completa
(2) Retorno do primeiro elemento da lista
(3) Retorno do enésimo elemento da lista
(4) Quantos elementos existem na lista?
(5) Busca pela chave ch na lista (ordem crescente) retornando p e ant
(6) Insercao da chave ch na lista ordenada sem duplicacoes
(7) Anexacao de novo elemento ao final da lista, duplicado ou nao
(8) Exclusao da chave dada
(9) Destruicao da lista */

#include <stdio.h>
#include <malloc.h>

// Definição da estrutura
typedef struct estrutura{
    int chave;              // valor do nó
    // int info;            // outros campos
    struct estrutura *prox; // sucessor do nó (autorreferência)
} NO;

typedef struct{
    NO *inicio;             // ponteiro para o primeiro nó
} LISTA_LIGADA_DINAMICA; 

#define false 0
#define true 1
typedef int bool;

// Protótipos funções de gerenciamento
void inicializarListaLigDinamica(LISTA_LIGADA_DINAMICA *lista);
void exibirListaLigDinamica(LISTA_LIGADA_DINAMICA *lista);      // (1)
int primeiroElemListaLigDinamica(LISTA_LIGADA_DINAMICA lista);  // (2)
int nElemListaLigDinamica(LISTA_LIGADA_DINAMICA lista, int n);  // (3)
int tamanhoListaLigDinamica(LISTA_LIGADA_DINAMICA *lista);      // (4)
NO* buscaElemAntListaLigDinamica(LISTA_LIGADA_DINAMICA *lista, int ch, NO* *ant); // (5)
bool insercaoElemOrdListaLigadaDinamica(LISTA_LIGADA_DINAMICA *lista, int ch);    // (6)
bool excluirElemListaLigEstat(LISTA_LIGADA_DINAMICA *lista, int ch);              // (8)
void reinicializarListaLigDinamica(LISTA_LIGADA_DINAMICA *lista);                 // (9)           
void menuOperacoes();

int main(){

    // Declaração lista do tipo lista ligada dinâmica
    LISTA_LIGADA_DINAMICA lista;
    NO *ant;

    // Inicialização da lista
    inicializarListaLigDinamica(&lista);

    // Inserir elementos
    insercaoElemOrdListaLigadaDinamica(&lista, 1);
    exibirListaLigDinamica(&lista);
    insercaoElemOrdListaLigadaDinamica(&lista, 3);
    exibirListaLigDinamica(&lista);
    insercaoElemOrdListaLigadaDinamica(&lista, 10);
    exibirListaLigDinamica(&lista);
    insercaoElemOrdListaLigadaDinamica(&lista, 2);
    exibirListaLigDinamica(&lista);
    insercaoElemOrdListaLigadaDinamica(&lista, 0);
    exibirListaLigDinamica(&lista);

    // Visualização da lista
    exibirListaLigDinamica(&lista);

    // Tarefa:
    int tarefa;
    menuOperacoes();

    while (tarefa != 0)
    {
        printf("Digite o número da operação desejada:\n");
        scanf("%d", &tarefa);

        int i, n, ch;
        switch (tarefa)
        {
        case 1:
            exibirListaLigDinamica(&lista);
            break;

        case 2:
            printf("Primeiro elemento da lista: %d\n", primeiroElemListaLigDinamica(lista));
            break;

        case 3:
            printf("Digite o n (n > 0) para o n-ésimo elemento a sua escolha:\n");
            scanf("%d", &n);
            printf("n-ésimo (n = %d) elemento da lista: %d\n", n, nElemListaLigDinamica(lista, n));
            break;
        
        case 4:
            printf("Tamanho da lista: %d\n", tamanhoListaLigDinamica(&lista));
            break;

        case 6:
            printf("Digite o elemento a ser inserido:\n");
            scanf("%d", &n);
            insercaoElemOrdListaLigadaDinamica(&lista, n);
            printf("Lista: ");
            exibirListaLigDinamica(&lista);
            break;

        case 8:
            printf("Digite o elemento a ser excluído:\n");
            scanf("%d", &n);
            printf("Lista antes: ");
            exibirListaLigDinamica(&lista);
            excluirElemListaLigEstat(&lista, n);
            printf("Lista depois: ");
            exibirListaLigDinamica(&lista);
            break;

        case 99:
            menuOperacoes();
            break;

        case 0:
            printf("FIM da operação\n");
            break;

        default:
            printf ("Valor invalido!\n");
            break;
        }
    }

    return 0;
}


// Menu operações
void menuOperacoes(){
    printf("Lista Ligada Dinâmica\n"); 
    printf("(1) Exibição da lista completa\n");
    printf("(2) Retorno do primeiro elemento da lista\n");
    printf("(3) Retorno do n-ésimo elemento da lista\n");
    printf("(4) Retorno do tamanho da lista sequencial\n");
    printf("(5) Busca pela chave na lista (ordem crescente)\n");
    printf("(6) Inserção da chave na lista ordenada sem duplicações\n");
    printf("(7) Anexação de novo elemento ao final da lista, duplicado ou não\n");
    printf("(8) Exclusão de chave dada\n");
    printf("(9) Destruição da lista\n");
    printf("(99) MENU OPERAÇÕES\n");
    printf("(0) EXIT\n");
}

// Funções de gerenciamneto
// * Inicialização da lista
void inicializarListaLigDinamica(LISTA_LIGADA_DINAMICA *lista){
    // criar lista vazia
    lista -> inicio = NULL;
}

// * Tamanho da lista
int tamanhoListaLigDinamica(LISTA_LIGADA_DINAMICA *lista){
    NO *end = lista->inicio; // pega o endereço
    int tam = 0;
    while (end != NULL){ // percorrer enquanto tiver endereço válido
        tam++;
        end = end->prox;
    }
    return tam;
}

// * Exibição da lista
void exibirListaLigDinamica(LISTA_LIGADA_DINAMICA *lista){ //pq por referencia?
    // percorrer enquanto tiver endereço válido
    // int i = lista -> inicio; // É UM ENDEREÇO, N UM INT!
    NO *end = lista -> inicio;
    while (end != NULL){
        printf("%d ", end->chave);
        end = end->prox;
    }
    printf("\n");
}

// * Primeiro elemento da lista
int primeiroElemListaLigDinamica(LISTA_LIGADA_DINAMICA lista){
    return lista.inicio->chave;
}

// * n-ésimo elemento da lista
int nElemListaLigDinamica(LISTA_LIGADA_DINAMICA lista, int n){
    NO *i;
    i = lista.inicio;  // endereço 1º elem
    
    if ( (n <= 0) || (n > tamanhoListaLigDinamica(&lista))){
        printf("n inválido (n > 0 ou fora da lista)! ");
        return -1;
    } 

    for (int j = 1; j < n; j++){
        i = i->prox; // dá segmentation fault para n além do que o número de nós; OK!
    }
    if (i != NULL) return i->chave;
    else return -1;
}

// * Busca por elemento
// OBS: não é possível fazer busca binária (eficiente), é preciso fazer busca sequencial (O(n))
// entrada: chave a ser procurada
// saída: endereço em que o elemento se encontra (cc. NULL)
NO* buscaSequencialListaLigDinamica(LISTA_LIGADA_DINAMICA *lista, int ch){
    // buscar enquanto tiver endereço válido
    NO *end = lista->inicio;
    while(end != NULL){
        if (end->chave == ch){ // encontrou
            printf("Elemento %d encontrado no endereço (n sei printar endereço)\n", ch);
            return end;
        }
        end = end->prox;
    }
    printf("Elemento %d não encontrado.\n", ch);
    return NULL; // não encontrou
}

NO* buscaSequencialOrdListaLigDinamica(LISTA_LIGADA_DINAMICA *lista, int ch){
    // considerando lista ordenada
    // se encontrar elemento com chave maior do que a procurada: não encontrou
    NO *end = lista->inicio;
    while((end != NULL) && (end->chave < ch)){
        end = end->prox;
    }
    if((end != NULL) && (end->chave == ch)){
        printf("Elemento %d encontrado no endereço (n sei printar endereço)\n", ch);
        return end;
    } 
    printf("Elemento %d não encontrado.\n", ch);
    return NULL;
}

// * Busca por elemento e seu antecessor
// retorno: endereço do elemento + endereço antecessor
// retorno múltiplo: uso de ponteiros
NO* buscaElemAntListaLigDinamica(LISTA_LIGADA_DINAMICA *lista, int ch, NO* *ant){
    // ponteiro para ponteiro: ant
    // a função é a mesma, única mudança: passa ponteiro *ant para salvar endereço antecessor
    NO *end = lista->inicio;
    *ant = NULL;                // anterior
    while((end != NULL) && (end->chave < ch)){
        *ant = end;
        end = end->prox;
    }
    if((end != NULL) && end->chave == ch) return end;
    return NULL;
    // de qqr forma, tem endereço do anterior: NULL 
}

// * Inserção de um elemento de forma ordenada, sem duplicação
bool insercaoElemOrdListaLigadaDinamica(LISTA_LIGADA_DINAMICA *lista, int ch){
    // buscar se o elemento esta presente
    NO *ant, *i;
    i = buscaElemAntListaLigDinamica(lista, ch, &ant);
    
    if(i != NULL){ // elemento já presente na lista
        printf("Elemento já presente na lista! Não foi inserido.\n");
        return false;
    }  

    // inserção elemento
    // alocação de memória para o novo elemento
    i = (NO*) malloc(sizeof(NO));
    i->chave = ch;

    // ajuste dos ponteiros
    if(ant == NULL){ // inicio da lista
        i->prox = lista->inicio;
        lista->inicio = i;
    }
    else{
        i->prox = ant->prox;
        ant->prox = i;
    }
    printf("Elemento %d inserido na lista.\n", ch);
    return true;
}

// * Exclusão de um elemento
bool excluirElemListaLigEstat(LISTA_LIGADA_DINAMICA *lista, int ch){
    // busca se o elemento está presente
    NO *i, *ant;
    i = buscaElemAntListaLigDinamica(lista, ch, &ant);

    if(i == NULL){
        printf("Elemento %d não está na lista para ser excluído.\n", ch);
        return false; // não está na lista
    } 

    // está na lista
    // 2 condições: tem ou n anterior?
    // ajusta os ponteiros
    if (ant == NULL) lista->inicio = i->prox; // sem anterior
    else ant->prox = i->prox;                 // com anterior
    // deleta a chave
    free(i);          // libera a memória 
    return true;
}

// * Reinicialização da lista
// cuidado: vários nós alocados, queremos zerá-la;
// temos que liberar a memória alocada, não basta apenas inicio->NULL 
/* void destruirListaLigDinamica(LISTA_LIGADA_DINAMICA *lista){
    lista->inicio = NULL;
} */
// não basta chamar apenas a função inicializar, temos que efetivamente liberar a memória
void reinicializarListaLigDinamica(LISTA_LIGADA_DINAMICA *lista){
    // laço por todos os elementos
    NO *end = lista->inicio;
    while (end != NULL){
        NO *apagar = end;  // variável auxiliar
        end = end->prox;
        free(apagar);      // libera a memória
    }
    // após apagar de fatio todos os elemetos
    lista->inicio = NULL;
}