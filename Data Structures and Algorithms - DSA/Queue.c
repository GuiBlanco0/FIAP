#include <stdio.h>
#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;


void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}


int enqueue(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return 0;
    }

    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;

    return 1;
}

int dequeue(Fila *f, int *valor) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return 0;
    }

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;

    return 1;
}

int main() {
    Fila f;
    int x;

    inicializarFila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    dequeue(&f, &x);
    printf("Removido: %d\n", x);

    dequeue(&f, &x);
    printf("Removido: %d\n", x);

    return 0;
}