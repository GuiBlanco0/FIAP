#include <stdio.h>

int buscaLinear(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int students; int grades[50]; char names[50][50]; int sum = 0; double med;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &students);

    while (students > 50 || students <= 0) {
        printf("Quantidade invalida, digite novamente: ");
        scanf("%d", &students);
    }
    for(int i = 0; i < students; i++){
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%d", &grades[i]);
        while (grades[i] > 10 || grades[i] < 0) {
            printf("Nota invalida, digite novamente: ");
            scanf("%d", &grades[i]);
        }
    }
    for(int i = 0; i < students; i++){
        sum += grades[i];
    }
    med = sum / (double)students;
    printf("%.1f", med);
    return 0;
}