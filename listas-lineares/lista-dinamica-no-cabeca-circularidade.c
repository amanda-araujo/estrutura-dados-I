/*
* Lista dinâmica com nó cabeça e circularidade
* ()
*
* Amanda Araujo Silva
*/

/* Tarefas:
(1) Exibicao da lista circular e com nó cabeça
(2) 1º. elemento da lista
(3) Ultimo elemento da lista 
(4) N-ésimo elemento da lista
(5) Quantos elementos existem?
(6) Posição da chave de busca na lista ordenada
(7) Inserção ordenada sem duplicidade
(8) Destruição da lista circular e com nó cabeça */

#include <stdio.h>
#include <malloc.h>

// Definição da estrutura
typedef struct estrutura {
    int chave;              // valor do nó 
    struct estrutura *prox; // aponta para o endereço do próximo nó
} NO;

typedef struct {
    NO *cabeca;                 // ponteiro para nó cabeça
} LISTA_LIGADA_CABECA_CIRCULAR;

#define true 1
#define false 0
typedef int bool;

// Funções de gerenciamento
// * Inicialização da lista
void inicializarListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista){
    // criar nó cabeça & apontar lista para nó cabeça
    lista->cabeca = (NO*) malloc(sizeof(NO));
    // ponteiro prox no cabeça: circular
    lista->cabeca->prox = lista->cabeca;
}

// * Tamanho da lista (nº de elementos válidos)
int tamanhoListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista){
    // percorrer a lista, em todos os nós válidos
    NO * end = lista->cabeca->prox;
    int tam = 0;
    // nunca passamos por NULL: último ligado ao cabeça
    while (end != lista->cabeca){ 
        tam++;
        end = end->prox;
    }
    return tam;
}

// * Exibição da lista
void exibirListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista){
    // nó cabeça não conta, não é válido
    NO *end = lista->cabeca->prox;
    // laço percorrendo lista até retornar ao nó cabeça 
    while (end != lista->cabeca) {
        printf("%d ", end->chave);
        end = end->prox;
    }
    printf("\n");
}

// * Busca por elemento
NO* buscaElemListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista, int ch){
    // nó cabeça pode ter a função de sentinela
    // colocar chave buscada no nó cabeça (única condição)
    NO *end = lista->cabeca->prox;
    lista->cabeca->chave = ch;
    // procurar enquanto != ch
    while(end->chave != ch) end = end->prox;
    if (end != lista->cabeca) return end; // encontrou sem ser no sentinela
    return NULL;
}

// * Busca por elemento e seu antecesor
NO* buscaSeqOrd(LISTA_LIGADA_CABECA_CIRCULAR *lista, int ch, NO* *ant){
    *ant = lista->cabeca;
    // usa nó cabeça de sentinela
    NO *end = lista->cabeca->prox;
    lista->cabeca->chave = ch;
    // busca pela chave percorrendo a lista ordenada
    while (end->chave < ch){
        *ant = end;
        end = end->prox;
    }
    // ch atual >= chave buscada
    if ((end != lista->cabeca) && end->chave == ch) return end;
    return NULL; // n achou
}

// * Inserção de um elemento ordenada sem duplicação
bool insercaoElemListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista, int ch){
    // precisamos saber anterior e posterior
    NO *ant, *i;
    i = buscaSeqOrd(lista, ch, &ant);
    if (i != NULL) return false; // n insere com repetição
    // inserção
    i = (NO*) malloc(sizeof(NO)); // alocar memória & guardar endereço
    i->chave = ch;                // copiar a chave
    // acertar ponteiros
    i->prox = ant->prox;
    ant->prox = i;
    return true;
}

// * Exclusão de um elemento da lista
bool excluirElemListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista, int ch){
    // busca elemento, precisamos saber anterior
    NO *i, *ant;
    i = buscaSeqOrd(lista, ch, &ant); // retorna endereço do elemento buscado
    if (i == NULL) return false; // o elemento não está na lista para ser excluído
    // exclusão
    ant->prox = i->prox; // acertar ponteiros
    free(i);             // liberar o nó
    return true;
}

// * Reinicialização da lista (exclusão da lista)
void reinicializarListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista){
    // liberar a memória de todos os nós, um por um dos válidos!
    // exclusão de todos elementos válidos
    NO *end;
    end = lista->cabeca->prox;  // endereço primeiro elem válido
    while (end != lista->cabeca){
        NO *aux = end;
        end = end->prox;
        free(aux);
    }
    // cabeça aponta para ele mesmo
    lista->cabeca->prox = lista->cabeca;
    // NÃO dá free no cabeça!
}

// * Primeiro elemento
int primeiroElemListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista){
    return lista->cabeca->prox->chave; 
}

// * n-ésimo elemento
int nElemListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista, int n){
    NO* end = lista->cabeca->prox; // percorrer elem válidos
    // n > 0 e n < tamanho
    if ((n <= 0) || (n > tamanhoListaLigDinCabecaCircular(lista))) return -1; // inválido
    for (int i = 1; i < n; i++){
        end = end->prox;
    }
    return end->chave; 
}

// * Último elemento
int ultimoElemListaLigDinCabecaCircular(LISTA_LIGADA_CABECA_CIRCULAR *lista){
    // percorrer toda lista de elementos válidos
    NO *end = lista->cabeca->prox;
    while (end->prox != lista->cabeca){
        end = end->prox;
    }
    return end->chave;
}

int main(){

    // Declarar lista
    LISTA_LIGADA_CABECA_CIRCULAR lista;
    NO *ant, *end;
    int n, ch;

    // Inicializar a lista
    inicializarListaLigDinCabecaCircular(&lista);

    // Inserir elementos
    insercaoElemListaLigDinCabecaCircular(&lista, 1);
    exibirListaLigDinCabecaCircular(&lista);
    insercaoElemListaLigDinCabecaCircular(&lista, 3);
    exibirListaLigDinCabecaCircular(&lista);
    insercaoElemListaLigDinCabecaCircular(&lista, 10);
    exibirListaLigDinCabecaCircular(&lista);
    insercaoElemListaLigDinCabecaCircular(&lista, 2);
    exibirListaLigDinCabecaCircular(&lista);

    // Tamanho
    printf("Tamanho da lista: %d\n", tamanhoListaLigDinCabecaCircular(&lista));

    // Primeiro elemento
    printf("Primeiro elemento da lista: %d\n", primeiroElemListaLigDinCabecaCircular(&lista));

    // n-ésimo elemento
    printf("Digite n (n > 0) para retornar o n-ésimo elemento da lista:\n");
    scanf("%d", &n);
    printf("n-ésimo elemento (n = %d) da lista: %d\n", n, nElemListaLigDinCabecaCircular(&lista, n));

    // Último elemento
    printf("último elemento da lista: %d\n", ultimoElemListaLigDinCabecaCircular(&lista));

    // Posição chave de busca
    printf("Elemento a ser buscado:\n");
    scanf("%d", &ch);
    end = buscaElemListaLigDinCabecaCircular(&lista, ch);
    printf("Posição (endereço) do elemento buscado %d: %x\n", ch, end); // devolve o endereço

    // Destruição (reinicialização da lista)
    reinicializarListaLigDinCabecaCircular(&lista);
    exibirListaLigDinCabecaCircular(&lista);
    printf("The END\n");

    return 0;
}
