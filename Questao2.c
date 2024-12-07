#include <stdio.h>

void mostraTab(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int mostraVen(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];
    return 0;
}

int main() {
    char tabuleiro[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int jogador = 1, jogadas = 0, vencedor = 0;
    int linha, coluna;

    while (jogadas < 9 && vencedor == 0) {
        mostraTab(tabuleiro);
        printf("Jogador %d, digite linha e coluna: ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != ' ') {
            printf("Jogada inválida, tente novamente.\n");
            continue;
        }

        tabuleiro[linha-1][coluna-1] = (jogador == 1) ? 'X' : 'O';
        vencedor = mostraVen(tabuleiro);
        jogador = (jogador == 1) ? 2 : 1;
        jogadas++;
    }

    mostraTab(tabuleiro);

    if (vencedor) 
        printf("Jogador %d venceu!\n", (vencedor == 'X') ? 1 : 2);
    else 
        printf("Empate!\n");

    return 0;
}
