#include <stdio.h>

#define LIMITE_TABULEIRO 8  // Definindo o limite do tabuleiro (8x8)
#define MOVIMENTO_BISPO 5   // O Bispo vai se mover até 5 casas na diagonal
#define MOVIMENTO_TORRE 5   // A Torre vai se mover até 5 casas para a direita
#define MOVIMENTO_RAINHA 8  // A Rainha vai se mover até 8 casas para a esquerda

// Nível Novato - Movimentação das Peças
void movimentarBispo(int posX, int posY) {
    printf("\nMovimento do Bispo (5 casas na diagonal superior direita):\n");
    for (int i = 1; i <= MOVIMENTO_BISPO; i++) {
        if (posX + i <= LIMITE_TABULEIRO && posY + i <= LIMITE_TABULEIRO)
            printf("Bispo pode se mover para (%d, %d) - Cima Direita\n", posX + i, posY + i);
    }
}

void movimentarTorre(int posX, int posY) {
    printf("\nMovimento da Torre (5 casas para a direita):\n");
    for (int i = 1; i <= MOVIMENTO_TORRE; i++) {
        if (posX + i <= LIMITE_TABULEIRO)
            printf("Torre pode se mover para (%d, %d) - Direita\n", posX + i, posY);
    }
}

void movimentarRainha(int posX, int posY) {
    printf("\nMovimento da Rainha (8 casas para a esquerda):\n");
    for (int i = 1; i <= MOVIMENTO_RAINHA; i++) {
        if (posX - i >= 1)
            printf("Rainha pode se mover para (%d, %d) - Esquerda\n", posX - i, posY);
    }
}

// Nível Aventureiro - Movimentação do Cavalo (em L)
void movimentarCavalo(int posX, int posY) {
    printf("\nMovimento do Cavalo (em L):\n");

    // Usando loops aninhados para simular as 8 possíveis movimentações do cavalo
    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Loop aninhado para verificar os movimentos possíveis
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 2; j++) {
            int novoX = posX + movimentos[i][0];
            int novoY = posY + movimentos[i][1];
            
            if (novoX >= 1 && novoX <= LIMITE_TABULEIRO && novoY >= 1 && novoY <= LIMITE_TABULEIRO) {
                printf("Cavalo pode se mover para (%d, %d)\n", novoX, novoY);
            }
        }
    }
}

// Nível Mestre - Movimentação Recursiva do Bispo
void movimentarBispoRecursivo(int posX, int posY, int casasRestantes) {
    if (casasRestantes > 0 && posX + 1 <= LIMITE_TABULEIRO && posY + 1 <= LIMITE_TABULEIRO) {
        printf("Bispo pode se mover para (%d, %d)\n", posX + 1, posY + 1);
        movimentarBispoRecursivo(posX + 1, posY + 1, casasRestantes - 1);
    }
}

// Movimentação do Cavalo (1 vez em L para cima à direita)
void movimentarCavaloMestre(int posX, int posY) {
    printf("\nMovimento do Cavalo (1 vez em L para cima à direita):\n");

    // Movimentos possíveis
    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Loop para verificar o movimento em L para cima à direita
    for (int i = 0; i < 8; i++) {
        if (movimentos[i][0] > 0 && movimentos[i][1] > 0) {
            int novoX = posX + movimentos[i][0];
            int novoY = posY + movimentos[i][1];

            if (novoX >= 1 && novoX <= LIMITE_TABULEIRO && novoY >= 1 && novoY <= LIMITE_TABULEIRO) {
                printf("Cavalo pode se mover para (%d, %d)\n", novoX, novoY);
                break;
            }
        }
    }
}

int main() {
    int posX = 4, posY = 4;  // Posição inicial das peças no tabuleiro

    // Nível Novato - Movimentação das Peças
    printf("### Nível Novato ###\n");
    movimentarBispo(posX, posY);
    movimentarTorre(posX, posY);
    movimentarRainha(posX, posY);

    // Nível Aventureiro - Movimentação do Cavalo
    printf("\n### Nível Aventureiro ###\n");
    movimentarCavalo(posX, posY);

    // Nível Mestre - Movimentação Recursiva do Bispo
    printf("\n### Nível Mestre ###\n");
    movimentarBispoRecursivo(posX, posY, MOVIMENTO_BISPO);

    // Movimentação do Cavalo (1 vez em L para cima à direita) no Nível Mestre
    movimentarCavaloMestre(posX, posY);

    return 0;
}
