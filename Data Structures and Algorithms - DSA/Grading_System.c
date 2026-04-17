#include <stdio.h>
 
int main() {
    int students; int grades[50]; char names[50][50]; int sum = 0; double med; int position = 0;
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
    int biggest_grade = grades[0]; int smallest_grade = grades[0];
    for (int i = 0; i < students; i++){
        if (grades[i] > biggest_grade){
            biggest_grade = grades[i];
            position = i;
        }
        if(smallest_grade > grades[i]){
            smallest_grade = grades[i];
        }
    }
    int pass_count = 0; int reprove_count = 0;
    for(int i = 0; i < students; i++){
        if (grades[i] < 6){
            reprove_count += 1;
        }
        else{
            pass_count += 1;
        }
    }
    printf("A media da turma e: %.1f", med);
    printf("\nA maior nota é %d e este na posição %d, e pertence ao aluno %s\nE a menor nota e %d", grades[position], position + 1, names[position], smallest_grade);
    printf("\nA quantidade de alunos que passou é: %d\nA quantidade de alunos reprovados e: %d", pass_count, reprove_count);
 
 
    return 0;
}