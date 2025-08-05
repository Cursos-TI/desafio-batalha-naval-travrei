#include <stdio.h>

// Desafio Batalha Naval - MateCheck
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int main() {
    // Nível Aventureiro
    //1. Represente o Tabuleiro
    int tabuleiro[LINHAS][COLUNAS];
    for(int y = 0; y < LINHAS; y++){
        for(int x = 0; x < COLUNAS; x++){
            tabuleiro[y][x] = 0;
        }
    }

    //2. Posicione os Navios
    int navio1[TAMANHO_NAVIO] = {3, 3, 3};
    int navio2[TAMANHO_NAVIO] = {3, 3, 3};
    int navio3[TAMANHO_NAVIO] = {3, 3, 3};
    int navio4[TAMANHO_NAVIO] = {3, 3, 3};

        //Posicionando Navio 1
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[3][i+2] = navio1[i];
    }
        //Posicionando Navio 2
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[i + 5][5] = navio2[i];
    }

        //Posicionando Navio 3 Diagonal
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[i + 6][i + 2] = navio3[i];
    }
        //Posicionando Navio 4 Diagonal
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[i][2 - i] = navio4[i];
    }

    //Exibir o Tabuleiro
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            printf("%d ", tabuleiro[y][x]);
        }
        printf("\n");
    }

    return 0;
}
