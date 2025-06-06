#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para verificar se há sobreposição
int verificaSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;

        // Verifica se está dentro dos limites e se não há outro navio
        if (x < 0 || x >= TAMANHO || y < 0 || y >= TAMANHO || tabuleiro[x][y] != AGUA) {
            return 1; // houve sobreposição ou fora do tabuleiro
        }
    }
    return 0; // ok
}

// Função para posicionar navio
void posicionaNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;
        tabuleiro[x][y] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicialização do tabuleiro com água (0)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // === Navio 1 - Horizontal ===
    int linha1 = 1, coluna1 = 2;
    if (!verificaSobreposicao(tabuleiro, linha1, coluna1, 0, 1)) {
        posicionaNavio(tabuleiro, linha1, coluna1, 0, 1);
    }

    // === Navio 2 - Vertical ===
    int linha2 = 4, coluna2 = 6;
    if (!verificaSobreposicao(tabuleiro, linha2, coluna2, 1, 0)) {
        posicionaNavio(tabuleiro, linha2, coluna2, 1, 0);
    }

    // === Navio 3 - Diagonal ↘ ===
    int linha3 = 0, coluna3 = 0;
    if (!verificaSobreposicao(tabuleiro, linha3, coluna3, 1, 1)) {
        posicionaNavio(tabuleiro, linha3, coluna3, 1, 1);
    }

    // === Navio 4 - Diagonal ↙ ===
    int linha4 = 2, coluna4 = 8;
    if (!verificaSobreposicao(tabuleiro, linha4, coluna4, 1, -1)) {
        posicionaNavio(tabuleiro, linha4, coluna4, 1, -1);
    }

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}