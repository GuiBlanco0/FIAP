#include <stdio.h>

int lerValor(char msg[]){
    int myNum;
    printf("%s: ", msg);
    scanf("%d", &myNum);
    return myNum;
}

int exibirArrayInteiro(int numeros[], int length){
    for(int i = 0; i < length; i++){
        printf("%d\n", numeros[i]);
    }
    return 0;
}

int main()
{
    int num; 
    int A[20]; 
    int fact;

    printf("Quantos números você quer saber o fatorial? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++){
        A[i] = lerValor("Digite seu número");
    }

    for (int i = 0; i < num; i++){
        fact = 1;
        for (int j = A[i]; j > 0; j--){
            fact = fact * j;
        }
        A[i] = fact;
    }
    exibirArrayInteiro(A, num);

    return 0;
}