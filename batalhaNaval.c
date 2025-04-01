#include <stdio.h>

int main() {
    int tabuleiro[10][10]; // Cria o tabuleiro 10x10
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define as posições iniciais dos navios
    int linhaHorizontal = 2, colunaHorizontal = 4; // Navio horizontal
    int linhaVertical = 5, colunaVertical = 7; // Navio vertical

    // Posiciona o navio horizontal (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posiciona o navio vertical (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Exibe o tabuleiro na tela
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Pula para a próxima linha
    }

    return 0;
}
