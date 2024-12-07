#include <stdio.h>

int somaRecursiva(int n) {
    if (n == 0)
        return 0;
    return n + somaRecursiva(n - 1);
}

int main() {
    int n;
    printf("Digite um mº positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Nº inválido\n");
    } else {
        printf("Somatória de 1 a %d: %d\n", n, somaRecursiva(n));
    }

    return 0;
}
