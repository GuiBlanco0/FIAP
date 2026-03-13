#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INSERT 100000
#define SEARCH 50000
#define REMOVE 20000

int main() {

    clock_t start, end;

    int *array = malloc(INSERT * sizeof(int));

    start = clock();

    // Inserção
    for(int i = 0; i < INSERT; i++){
        array[i] = i;
    }

    // Busca
    for(int i = 0; i < SEARCH; i++){
        int target = rand() % INSERT;

        for(int j = 0; j < INSERT; j++){
            if(array[j] == target){
                break;
            }
        }
    }

    // Remoção (simples)
    for(int i = 0; i < REMOVE; i++){
        array[i] = -1;
    }

    end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tempo de execucao (Array): %f segundos\n", time);

    free(array);

    return 0;
}