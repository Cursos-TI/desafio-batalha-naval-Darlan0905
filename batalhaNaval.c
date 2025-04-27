#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0}; // Inicializa tudo com água (0)

    
    // Definição da Cruz (valor 3)
    
    int cruz[5][5] = {0}; // Matriz da habilidade cruz
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // Linha do meio
        cruz[i][2] = 1; // Coluna do meio
    }

    // Origem da cruz no tabuleiro (linha, coluna)
    int cruzLinha = 2;
    int cruzColuna = 4;

    // Aplicar a cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaTab = cruzLinha - 2 + i;
            int colunaTab = cruzColuna - 2 + j;

            if (linhaTab >= 0 && linhaTab < LINHAS && colunaTab >= 0 && colunaTab < COLUNAS) {
                if (cruz[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 3;
                }
            }
        }
    }

    // Definição do Octaedro (valor 2)
    int octaedro[5][5] = {0}; // Matriz da habilidade octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j >= 2 && i + j <= 6 && j - i <= 2 && i - j <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Origem do octaedro no tabuleiro
    int octaedroLinha = 4;
    int octaedroColuna = 6;

    // Aplicar o octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaTab = octaedroLinha - 2 + i;
            int colunaTab = octaedroColuna - 2 + j;

            if (linhaTab >= 0 && linhaTab < LINHAS && colunaTab >= 0 && colunaTab < COLUNAS) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 2;
                }
            }
        }
    }

    
    // Definição do Cone (valor 1)
    
    int cone[5][5] = {0}; // Matriz da habilidade cone
    for (int i = 0; i < 5; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >= 0 && j < 5) {
                cone[i][j] = 1;
            }
        }
    }

    // Origem do cone no tabuleiro
    int coneLinha = 6;
    int coneColuna = 2;

    // Aplicar o cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaTab = coneLinha - 2 + i;
            int colunaTab = coneColuna - 2 + j;

            if (linhaTab >= 0 && linhaTab < LINHAS && colunaTab >= 0 && colunaTab < COLUNAS) {
                if (cone[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 1;
                }
            }
        }
    }

    // ---------------------------------
    // Impressão do tabuleiro final
    // ---------------------------------
    printf("  ");
    for (int j = 0; j < COLUNAS; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
