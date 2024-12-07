#include <stdio.h>

int main() {
    float indices[7][6];
    float medMen[6] = {0}, medCid[7] = {0};

    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Insira indices pluviométricos dq cidade %d:\n", cidade + 1);
        for (int mes = 0; mes < 6; mes++) {
            printf("Mês %d: ", mes + 1);
            scanf("%f", &indices[cidade][mes]);
            medCid[cidade] += indices[cidade][mes];
            medMen[mes] += indices[cidade][mes];
        }
        medCid[cidade] /= 6.0;
    }

    for (int mes = 0; mes < 6; mes++) 
        medMen[mes] /= 7.0;

    printf("\nÍndice médio mensal Cidade:\n");
    for (int cidade = 0; cidade < 7; cidade++) 
        printf("Cidade %d: %.2f\n", cidade + 1, medCid[cidade]);

    printf("\nÍndice médio por mês Região:\n");
    for (int mes = 0; mes < 6; mes++) 
        printf("Mês %d: %.2f\n", mes + 1, medMen[mes]);

    return 0;
}
