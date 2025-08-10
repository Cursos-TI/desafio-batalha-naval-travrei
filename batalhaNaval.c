#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

//Definindo numeros
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5


int main() {
    // Nível Aventureiro
    //1. Represente o Tabuleiro
    int tabuleiro[LINHAS][COLUNAS];
    for(int y = 0; y < LINHAS; y++){
        for(int x = 0; x < COLUNAS; x++){
            tabuleiro[y][x] = AGUA;
        }
    }

    //2. Posicione os Navios
        //Posicionando Navio 1
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[3][i+2] = NAVIO;
    }
        //Posicionando Navio 2
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[i + 5][5] = NAVIO;
    }

        //Posicionando Navio 3 Diagonal
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[i + 6][i + 2] = NAVIO;
    }
        //Posicionando Navio 4 Diagonal
    for(int i = 0; i < TAMANHO_NAVIO; i++){
        tabuleiro[i][2 - i] = NAVIO;
    }

    //Criando as Habilidades
    int centro = TAMANHO_HABILIDADE / 2;

    //CONE
    int hab_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {AGUA};
    for(int y = 0; y < TAMANHO_HABILIDADE; y++){
        for (int x = 0; x < TAMANHO_HABILIDADE; x++){
            if (y >= abs(x - centro) && !(y > centro)){
                hab_cone[y][x] = HABILIDADE;
            }
        }
    }

    //CRUZ
    int hab_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {AGUA};
    for (int y = 0; y < TAMANHO_HABILIDADE; y++){
        for(int x = 0; x < TAMANHO_HABILIDADE; x++){
            if (x == centro || y == centro){
                hab_cruz[y][x] = HABILIDADE;
            }
        }
    }

    //OCTAEDRO
    int hab_octa[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {AGUA};
    for(int y = 0; y < TAMANHO_HABILIDADE; y++){
        for(int x = 0; x < TAMANHO_HABILIDADE; x++){
            if(abs(x - centro) + abs(y - centro) <= centro){
                hab_octa[y][x] = HABILIDADE;
            }
        }
    }

    //Aplicando as habilidades no Tab.

    for(int y = 0; y < TAMANHO_HABILIDADE; y++){
        for(int x = 0; x < TAMANHO_HABILIDADE; x++){
            tabuleiro[y+2][x+4] = hab_cone[y][x];
            tabuleiro[y+5][x+1] = hab_cruz[y][x];
            tabuleiro[y][x] = hab_octa[y][x];
        }
    }

    /*
    //Printando as habilidades para Teste
    for(int y = 0; y < TAMANHO_HABILIDADE; y++){
        for(int x = 0; x < TAMANHO_HABILIDADE; x++){
            printf("%d ", hab_cone[y][x]);
        }
        printf("\n");
    }
    */

    
    //Exibir o Tabuleiro
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    printf("   ---------------------\n");
    for(int y = 0; y < LINHAS; y++){
        printf("%d |", y);
        for(int x = 0; x < COLUNAS; x++){
            printf("%d ", tabuleiro[y][x]);
        }
        printf("\n");
    }
    
    return 0;
}
