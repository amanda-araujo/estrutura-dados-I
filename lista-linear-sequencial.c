/*
* Lista linear sequencial
* (ordem lógica = ordem física)
*
* Amanda Araujo Silva
*/

#include <stdio.h>

/* A forma mais comum de implementação: vetor de elementos do 
tipo REGISTRO de tamanho MAX*/

#define MAX 50 // Tamanho vetor
#define false 0
#define true 1

typedef int bool;

typedef struct{
    int chave;
    // outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX]; // Vetor de elementos
    int nElem;       // Número de posições efetivamente ocupadas
} LISTA_LINEAR_SEQ;

// Protótipos funções de gerenciamento
void inicializarListaSeq(LISTA_LINEAR_SEQ *lista);
void exibirListaSeq(LISTA_LINEAR_SEQ lista);
int tamanhoListaSeq(LISTA_LINEAR_SEQ lista);
int primeiroElemListaSeq(LISTA_LINEAR_SEQ lista);
int ultimoElemListaSeq(LISTA_LINEAR_SEQ lista);
int nesimoElemListaSeq(LISTA_LINEAR_SEQ lista, int n);
void destruirListaSeq(LISTA_LINEAR_SEQ *lista);
bool inserirListaSeq(LISTA_LINEAR_SEQ *lista, int i, int ch);
bool buscaSeqListaSeq(LISTA_LINEAR_SEQ lista, int ch);
void menuOperacoes();

int main(){
    
    int tarefa;
    LISTA_LINEAR_SEQ lista; // declaração lista do tipo LISTA_LINEAR_SEQ
    
    inicializarListaSeq(&lista); // lista vazia
    //exibirListaSeq(lista);

    // Adicionar elementos na lista:
    for(int i = 0; i < 10; i++){
        lista.A[i].chave = i*10;
        lista.nElem++;
    }
    printf("Lista: ");
    exibirListaSeq(lista);
    
    // Tarefa:
    menuOperacoes();
    
    while (tarefa != 0)
    {
    printf("Digite o número da operação desejada:\n");
    scanf("%d", &tarefa);

    int i, n, ch;
    switch (tarefa)
    {
    case 1:
        exibirListaSeq(lista);
        break;
    
    case 2:
        printf("Tamanho da lista: %d\n", tamanhoListaSeq(lista));
        break;
    
    case 3:
        printf("Primeiro elemento da lista: %d\n", primeiroElemListaSeq(lista));
        break;
    
    case 4:
        printf("Primeiro elemento da lista: %d\n", ultimoElemListaSeq(lista));
        break;
    
    case 5:
        printf("Digite n para obter o n-ésimo elemento da lista (n > 0): \n");
        scanf("%d", &n);

        if(nesimoElemListaSeq(lista, n) != -1) printf("Chave do %d-ésimo elemento: %d\n", n, nesimoElemListaSeq(lista, n));
        else printf("Valor inválido\n");
        break;

    case 6:
        destruirListaSeq(&lista);
        printf("Lista destruída!\n");
        break;
    
    case 7:
        printf("Valor do elemento a ser inserido: \n");
        scanf("%d", &ch);
        
        printf("Posição de inserção (contagem começa na posição 0): \n");
        scanf("%d", &i);
        
        inserirListaSeq(&lista, i, ch);
        
        printf("Nova lista: ");
        exibirListaSeq(lista);
        break;

    case 8:
        printf("Inserir chave buscada: \n");
        scanf("%d", &ch);

        if(buscaSeqListaSeq(lista, ch)) printf("Chave %d presente na lista\n", ch);
        else printf("Chave ausente\n");
        break;
    
    case 9:
        /* code */
        break;
    
    case 10:
        /* code */
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



// Funções de gerenciamento

void menuOperacoes(){
    printf("Listas Lineares Sequenciais\n"); 
    printf("(1) Exibição da lista sequencial\n");
    printf("(2) Retorno do tamanho da lista sequencial\n");
    printf("(3) Retorno da chave do primeiro elemento da lista sequencial\n");
    printf("(4) Retorno da chave do ultimo elemento da lista sequencial\n");
    printf("(5) Retorno da chave do n-ésimo elemento da lista sequencial\n");
    printf("(6) Destruição da lista sequencial\n");
    printf("(7) Inserção direta na posição i\n");
    printf("(8) Busca sequencial em lista (ordenada por chave ou não)\n");
    printf("(9) Busca sequencial em lista com sentinela (vetor criado com max+1 posições)\n");
    printf("(10) Busca binária em lista ordenada\n");
    printf("(99) MENU OPERAÇÕES\n");
    printf("(0) EXIT\n");
}

// * Inicialização 
/* void inicializarLista(LISTA_LINEAR_SEQ lista){
    lista.nElem = 0;
}; */

// Há algum problema com esse código? SIM, inicializa apenas a cópia
// Qual a diferença entre os códigos? Passagem por valor (cópia) vs. por referência

void inicializarListaSeq(LISTA_LINEAR_SEQ *lista){ // ponteiro, alteração no original
    lista -> nElem = 0; // acesso campo struct por ponteiro (operador seta)
};

// * Exibição da lista sequencial
void exibirListaSeq(LISTA_LINEAR_SEQ lista){ // cópia, apenas visualização
    // Print elementos de um vetor
    for(int i = 0; i < lista.nElem; i++){
        printf("%d ", lista.A[i].chave); // tipo chave: int (%d) 
    }
    printf("\n");
}

// * Retorno tamanho da lista (número de elementos)
int tamanhoListaSeq(LISTA_LINEAR_SEQ lista){ // cópia, apenas visualização
    return lista.nElem; // acesso campo struct operador ponto
};

// * Chave primeiro elemento da lista
int primeiroElemListaSeq(LISTA_LINEAR_SEQ lista){
    if(lista.nElem > 0) return lista.A[0].chave; // checagem se há algum elemento
    else return (-1); // lista vazia
}

// * Chave último elemento da lista
int ultimoElemListaSeq(LISTA_LINEAR_SEQ lista){
    if(lista.nElem > 0) return lista.A[(lista.nElem - 1)].chave; //última posição ocupada
    else return (-1); // lista vazia
}

// * Chave n-ésimo elemento da lista
int nesimoElemListaSeq(LISTA_LINEAR_SEQ lista, int n){
    if(n > 0 && n <= lista.nElem) return lista.A[n - 1].chave; // checagem índice n na lista
    else return (-1); // índice fora do escopo ou lista vazia
}

// * Destruição da lista
void destruirListaSeq(LISTA_LINEAR_SEQ *lista){ // ponteiro, alteração no original
    lista -> nElem = 0; 
}

// * Inserção direta na posição i (lista, posição, valor)
bool inserirListaSeq(LISTA_LINEAR_SEQ *lista, int i, int ch){ // ponteiro, alteração no original
    // Checagem se há espaço, se a posição está ocupada (tem que estar)
    if((i < 0) || (i > (lista -> nElem)) || ((lista -> nElem) >= MAX)){
        return false; // índice inválido ou lista cheia
    }
    if(((lista -> nElem) >= 0) && (i <= (lista -> nElem))){ // válido
        // Deslocar todos da posição pra cima para frente
        for(int j = (lista -> nElem); j >= (i + 1); j--){ // começa do último e pula todos
            lista -> A[j] = lista -> A[j - 1]; 
        }
        lista -> A[i].chave = ch; // preencher o novo valor na posição desejada
        lista -> nElem++;   // atualizar número de elementos
        return true;
    }
}

// * Busca sequencial (lista ordenada por chave ou não) :: percorre todos os elementos
bool buscaSeqListaSeq(LISTA_LINEAR_SEQ lista, int ch){
    int i = 0;
    while(i < lista.nElem){
        if(lista.A[i].chave == ch) return true;
        else i++;
    }
    return false;
}

// * Busca sequencial com sentinela

// * Busca binária em lista ordenada

// * Deleção direta na posição i

// * Deleção de uma chave 