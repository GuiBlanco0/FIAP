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

int main(){
    int A[10];
    int B[10];
    for(int i = 0; i < 10; i++){
        A[i] = lerValor("Digite seu número");
    }
    for(int i = 0; i < 10; i++){
        if(A[i] % 2 == 0){
            B[i] = A[i] * 5;
        }
        else{
            B[i] = A[i] + 5;
        }
    }
    printf("\nVetor B:\n");
    exibirArrayInteiro(B, 10);
    return 0;
}