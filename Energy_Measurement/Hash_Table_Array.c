#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100003
#define INSERT 100000
#define SEARCH 50000
#define REMOVE 20000

int table[SIZE];

int hash(int key){
    return key % SIZE;
}

void insert(int key){
    int index = hash(key);

    while(table[index] != 0){
        index = (index + 1) % SIZE;
    }

    table[index] = key;
}

int search(int key){

    int index = hash(key);

    while(table[index] != 0){

        if(table[index] == key)
            return 1;

        index = (index + 1) % SIZE;
    }

    return 0;
}

void removeKey(int key){

    int index = hash(key);

    while(table[index] != 0){

        if(table[index] == key){
            table[index] = 0;
            return;
        }

        index = (index + 1) % SIZE;
    }
}

int main(){

    clock_t start = clock();

    for(int i = 1; i <= INSERT; i++){
        insert(i);
    }

    for(int i = 0; i < SEARCH; i++){
        search(rand() % INSERT);
    }

    for(int i = 0; i < REMOVE; i++){
        removeKey(i);
    }

    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tempo de execucao (Hash Table): %.8f segundos\n", time);

    return 0;
}