#include <stdio.h>

#define TAMANHO 10
#define HABILIDADE 5

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Ponto de origem das habilidades
    int origemCone[2] = {2, 2};
    int origemCruz[2] = {5, 5};
    int origemOctaedro[2] = {7, 7};
    
    // Aplicação da habilidade Cone
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            int linha = origemCone[0] + i;
            int coluna = origemCone[1] + j;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }
    
    // Aplicação da habilidade Cruz
    for (int i = -2; i <= 2; i++) {
        int linha = origemCruz[0] + i;
        int coluna = origemCruz[1];
        if (linha >= 0 && linha < TAMANHO) {
            tabuleiro[linha][coluna] = HABILIDADE;
        }
        linha = origemCruz[0];
        coluna = origemCruz[1] + i;
        if (coluna >= 0 && coluna < TAMANHO) {
            tabuleiro[linha][coluna] = HABILIDADE;
        }
    }
    
    // Aplicação da habilidade Octaedro
    for (int i = -2; i <= 2; i++) {
        int limite = (i < 0) ? -i : i; // Simula abs(i) sem usar <stdlib.h>
        for (int j = -2 + limite; j <= 2 - limite; j++) {
            int linha = origemOctaedro[0] + i;
            int coluna = origemOctaedro[1] + j;
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }

    // Exibe o tabuleiro formatado
    printf("\n   "); // Espaço para alinhamento
    for (int j = 0; j < TAMANHO; j++) {
        printf("%2d ", j); // Cabeçalho das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i); // Índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Valores formatados
        }
        printf("\n");
    }
    
    return 0;
}

