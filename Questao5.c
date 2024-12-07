#include <stdio.h>

int main() {
    printf("Questão 5\n");
    printf("x = 3; y = 4; p = endereço de memória do y.\n");
    printf("x = *p;  --> x recebe 0\n");
    printf("x = 4;   --> x é 4\n");
    printf("(*p)++;  --> y incrementa, vira 1\n");
    printf("--x;     --> x decrementa, vira 3\n");
    printf("(*p) += x; --> 1 + 3 = 4\n");
    return 0;
}
