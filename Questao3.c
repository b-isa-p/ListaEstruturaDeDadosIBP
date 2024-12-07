#include <stdio.h>

int main() {
    float notas[5][4], medA[5], medT = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite 4 notas do alunp %d: ", i + 1);
        medA[i] = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%f", &notas[i][j]);
            medA[i] += notas[i][j];
        }
        medA[i] /= 4.0;
        medT += medA[i];
    }

    medT /= 5.0; //dividindo p aluno

    printf("\nMédias dos alunos:\n");
    for (int i = 0; i < 5; i++) 
        printf("Aluno %d: %.2f\n", i + 1, medA[i]);
    printf("Média da  turma: %.2f\n", medT);

    return 0;
}

