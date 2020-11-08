#include <iostream>

// Struct que cria uma lista
struct Lista {
    int val;
    struct Lista *next;
};

// Protótipos das funções
void exibirFila(struct Lista *pFila);
void enfileirarFila (int cont);
void desenfileirar();

// Declaração da TAD fila
struct Lista *list = NULL;
struct Lista *tail;

// método principal
int main(int argc, char const *argv[]) {

    // Exibição da lista vazia
    exibirFila(list);

    // incerção de valores na lista
    enfileirarFila(10);
    enfileirarFila(20);
    enfileirarFila(30);

    // Exibição da lista com os valores novos
    exibirFila(list);

    // Exclusão do primeiro item da lista
    desenfileirar();

    // Exibição da lista modificada
    exibirFila(list);

    return 0;
}

// método para adicionar/enfileirar itens na lista
void enfileirarFila (int cont){

    //declaração de um novo item
    struct Lista *novo;
    novo = (struct Lista *) malloc(sizeof(struct Lista));

    // associação de valores
    novo -> val = cont;
    novo -> next = NULL;

    // condicional para verificar se a lista está vazia.
    // Se sim, a cabeça(primeiro item) da lista recebe o novo valor.
    // Senão, o ultimo item referencia o novo valor.
    if(list == NULL){
        list = novo;
    }else{
        tail -> next = novo;
    }

    // Em ambos os casos, o ultimo elemento recebe o novo valor.
    tail = novo;
}

// Método para exibir os elementos da lista.
void exibirFila(struct Lista *pFila){

    // Declaração de um auxiliar para fazer um loop
    struct Lista *aux;
    aux = pFila;
    int cont = 0;

    // Se a lista estiver vazia ele não percorre ela
    // Se tiver algum item, ele os exibe
    if(aux!=NULL){
        while(aux != NULL){
            printf("Posicao Fila[%d]\nLocal Memoria: %x\nValor: %d\n", cont, aux, aux->val);
            aux = aux->next;
            cont++;
        }
    } else{
        printf("A Fila esta vazia\n");
    }
    printf("\n\n");
}

// Método que remove um item da lista
void desenfileirar(){

    // Declaração de um auxiliar para a transferencia de valores
    struct Lista *aux;
    aux = list;

    // Transferencia do segundo item da lista para o primeiro
    list = list -> next;

    // Liberação do espaço não ultilizado
    free(aux);
}
