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
    int A[5]; 
    int sum = 0;

    for(int i = 0; i < 5; i++){
        A[i] = lerValor("Digite seu número");
    }
    
    for(int i = 0; i < 5; i++){
        if(A[i] % 2 == 1){
            sum += A[i];
        }
    }
    printf("%d", sum);
    return 0;
}