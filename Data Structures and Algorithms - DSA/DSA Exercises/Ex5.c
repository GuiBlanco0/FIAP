#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Inserir no início
Node* insertBegin(Node* head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Inserir no fim
Node* insertEnd(Node* head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* aux = head;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = newNode;
    return head;
}

// Remover valor
Node* removeValue(Node* head, int value) {
    if (head == NULL) return head;

    // remover primeiro
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* aux = head;
    while (aux->next != NULL && aux->next->data != value) {
        aux = aux->next;
    }

    if (aux->next == NULL) return head; // não achou

    Node* temp = aux->next;
    aux->next = aux->next->next;
    free(temp);
    return head;
}

// Imprimir lista
void printList(Node* head) {
    Node* aux = head;
    while (aux != NULL) {
        printf("%d -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}

//Lenght
int lenght(Node* head) {
    int i = 0;
    Node* aux = head;
    while (aux != NULL) {
        i++;
        aux = aux->next;
    }
    return i;
}

//Search
int search(Node* head, int value) {
    int i = 0;
    Node* aux = head;
    while (aux != NULL) {
        if (aux->data == value){
            return i;
        }
        i++;
        aux = aux->next;
    }
    return -1;
}

//Invert

int main() {
    Node* head = NULL;

    head = insertBegin(head, 10);
    head = insertEnd(head, 20);
    head = insertBegin(head, 5);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    head = insertBegin(head, 15);
    printList(head);

    head = removeValue(head, 10);
    
    printList(head);
    printf("Número de elementos %d\n", lenght(head));
    printf("Buscando por 20: %d", search(head, 20));

    return 0;
}