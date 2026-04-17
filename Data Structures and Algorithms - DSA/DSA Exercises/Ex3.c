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
    int A[20]; int B[20]; int C[20];
    for(int i = 0; i < 20; i++){
        A[i] = lerValor("Digite seu número");
    }
    for(int i = 0; i < 20; i++){
        B[i] = A[i] * i;
        C[i] = A[i] - B[i];
    }
    exibirArrayInteiro(A, 20);
    exibirArrayInteiro(B, 20);
    exibirArrayInteiro(C, 20);
    return 0;
}