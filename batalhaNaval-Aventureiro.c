#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definição fixa das posições iniciais dos navios
    int posicoes[4][4] = {
        {1, 2, 0, 1}, // Navio horizontal
        {4, 5, 1, 0}, // Navio vertical
        {2, 2, 1, 1}, // Navio diagonal principal
        {6, 7, 1, -1} // Navio diagonal secundária
    };

    // Posiciona os navios no tabuleiro
    for (int i = 0; i < 4; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        int deltaLinha = posicoes[i][2];
        int deltaColuna = posicoes[i][3];
        
        int podeColocar = 1;
        for (int j = 0; j < 3; j++) {
            int novaLinha = linha + j * deltaLinha;
            int novaColuna = coluna + j * deltaColuna;
            
            if (novaLinha < 0 || novaLinha >= TAMANHO || novaColuna < 0 || novaColuna >= TAMANHO || tabuleiro[novaLinha][novaColuna] == NAVIO) {
                podeColocar = 0;
                break;
            }
        }
        
        if (podeColocar) {
            for (int j = 0; j < 3; j++) {
                tabuleiro[linha + j * deltaLinha][coluna + j * deltaColuna] = NAVIO;
            }
        }
    }

    // Exibe o tabuleiro com os navios posicionados
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
