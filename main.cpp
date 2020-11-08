#include <iostream>

struct Lista {
    int val;
    struct Lista *next;
};

void exibirFila(struct Lista *pFila);
void enfileirarFila (int cont);
void desenfileirar();

struct Lista *list = NULL;
struct Lista *tail;

int main(int argc, char const *argv[]) {

    enfileirarFila(10);
    enfileirarFila(20);
    enfileirarFila(30);
    exibirFila(list);
    desenfileirar();
    exibirFila(list);

    return 0;
}

void enfileirarFila (int cont){
    struct Lista *novo;
    novo = (struct Lista *) malloc(sizeof(struct Lista));

    novo -> val = cont;
    novo -> next = NULL;

    if(list == NULL){
        list = novo;
    }else{
        tail -> next = novo;
    }
    tail = novo;
}

void exibirFila(struct Lista *pFila){
    struct Lista *aux;
    aux = pFila;
    int cont = 0;
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

void desenfileirar(){
    struct Lista *aux;
    aux = list;
    list = list -> next;
    free(aux);
}
