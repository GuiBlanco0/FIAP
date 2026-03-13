#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INSERT 100000
#define SEARCH 50000
#define REMOVE 20000

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* insert(Node *head, int value){

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;

    return newNode;
}

Node* removeNode(Node *head){

    if(head == NULL) return NULL;

    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

int search(Node *head, int value){

    Node *current = head;

    while(current != NULL){
        if(current->data == value) return 1;
        current = current->next;
    }

    return 0;
}

int main(){

    Node *head = NULL;

    clock_t start = clock();

    for(int i = 0; i < INSERT; i++){
        head = insert(head, i);
    }

    for(int i = 0; i < SEARCH; i++){
        search(head, rand() % INSERT);
    }

    for(int i = 0; i < REMOVE; i++){
        head = removeNode(head);
    }

    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tempo de execucao (Linked List): %f segundos\n", time);

    return 0;
}