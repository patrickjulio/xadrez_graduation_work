#include "xadrez.h"

// ============================================================================
// SEÇÃO 1: FUNÇÕES UTILITÁRIAS
// ============================================================================

// Limpa a tela do terminal
static void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Imprime uma linha separadora com título
void imprimir_separador(const char* titulo) {
    printf("\n===========================================\n");
    if (titulo) printf("  %s\n", titulo);
    printf("===========================================\n");
}

// ============================================================================
// SEÇÃO 2: FUNÇÕES DE INICIALIZAÇÃO E IMPRESSÃO DO TABULEIRO
// ============================================================================

// Preenche o tabuleiro com '.'
void inicializar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

// Imprime letras das colunas do tabuleiro
static void imprimir_linha_colunas() {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

// Imprime o tabuleiro com linhas e colunas
void imprimir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n");
    imprimir_linha_colunas();
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    imprimir_linha_colunas();
    printf("\n");
}

// Imprime o tabuleiro com título
void imprimir_tabuleiro_titulo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], const char* titulo) {
    printf("\n%s\n", titulo);
    imprimir_tabuleiro(tabuleiro);
}

// ============================================================================
// SEÇÃO 3: FUNÇÕES DE VALIDAÇÃO E MANIPULAÇÃO DE PEÇAS
// ============================================================================

// Verifica se a posição está dentro dos limites do tabuleiro
bool posicao_valida(Posicao pos) {
    return pos.linha >= 0 && pos.linha < TAMANHO_TABULEIRO &&
           pos.coluna >= 0 && pos.coluna < TAMANHO_TABULEIRO;
}

// Retorna o símbolo correspondente ao tipo de peça
char obter_simbolo_peca(TipoPeca tipo) {
    switch (tipo) {
        case TORRE:   return 'T';
        case BISPO:   return 'B';
        case RAINHA:  return 'R';
        default:      return '.';
    }
}

// Retorna o nome da peça
const char* obter_nome_peca(TipoPeca tipo) {
    switch (tipo) {
        case TORRE:   return "Torre";
        case BISPO:   return "Bispo";
        case RAINHA:  return "Rainha";
        default:      return "Vazio";
    }
}

// Identifica o tipo de peça pelo símbolo
static TipoPeca obter_tipo_por_simbolo(char simbolo) {
    switch (simbolo) {
        case 'T': return TORRE;
        case 'B': return BISPO;
        case 'R': return RAINHA;
        default:  return VAZIO;
    }
}

// Valida se o movimento é horizontal ou vertical
bool movimento_valido_torre(Posicao origem, Posicao destino) {
    return (origem.linha == destino.linha && origem.coluna != destino.coluna) ||
           (origem.coluna == destino.coluna && origem.linha != destino.linha);
}

// Valida se o movimento é diagonal
bool movimento_valido_bispo(Posicao origem, Posicao destino) {
    int diff_linha = abs(destino.linha - origem.linha);
    int diff_coluna = abs(destino.coluna - origem.coluna);
    return diff_linha == diff_coluna && diff_linha > 0;
}

// Valida se o movimento é horizontal, vertical ou diagonal
bool movimento_valido_rainha(Posicao origem, Posicao destino) {
    return movimento_valido_torre(origem, destino) ||
           movimento_valido_bispo(origem, destino);
}

// Valida o movimento de acordo com o tipo de peça
static bool validar_movimento(TipoPeca tipo, Posicao origem, Posicao destino) {
    switch (tipo) {
        case TORRE:   return movimento_valido_torre(origem, destino);
        case BISPO:   return movimento_valido_bispo(origem, destino);
        case RAINHA:  return movimento_valido_rainha(origem, destino);
        default:      return false;
    }
}

// ============================================================================
// SEÇÃO 4: FUNÇÕES DE MOVIMENTAÇÃO NO TABULEIRO
// ============================================================================

// Inicializa o tabuleiro e posiciona a peça
void preparar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Posicao pos, char simbolo) {
    inicializar_tabuleiro(tabuleiro);
    tabuleiro[pos.linha][pos.coluna] = simbolo;
}

// Marca os movimentos possíveis de uma peça no tabuleiro
void marcar_movimentos(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Posicao origem) {
    TipoPeca tipo = obter_tipo_por_simbolo(tabuleiro[origem.linha][origem.coluna]);
    
    if (tipo == VAZIO) {
        printf("Nenhuma peça válida nesta posição!\n");
        return;
    }
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == '.' && validar_movimento(tipo, origem, (Posicao){i, j})) {
                tabuleiro[i][j] = '*';
            }
        }
    }
}

// Marca o caminho de uma peça a partir da origem, usando deslocamento
void marcar_caminho_e_posicionar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Posicao origem, int d_linha, int d_coluna, int num_passos, char simbolo) {
    inicializar_tabuleiro(tabuleiro);
    Posicao pos_final = origem;
    for (int i = 0; i < num_passos; i++) {
        int nova_linha = pos_final.linha + d_linha;
        int nova_coluna = pos_final.coluna + d_coluna;
        if (nova_linha < 0 || nova_linha >= TAMANHO_TABULEIRO || nova_coluna < 0 || nova_coluna >= TAMANHO_TABULEIRO) break;
        pos_final.linha = nova_linha;
        pos_final.coluna = nova_coluna;
        tabuleiro[pos_final.linha][pos_final.coluna] = '+';
    }
    tabuleiro[pos_final.linha][pos_final.coluna] = simbolo;
}

// Marca o caminho de uma peça usando um vetor de movimentos
void marcar_caminho_vetor(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Posicao origem, int movimentos[][2], int num_movimentos, char simbolo) {
    inicializar_tabuleiro(tabuleiro);
    Posicao pos = origem;
    for (int i = 0; i < num_movimentos; i++) {
        int nova_linha = pos.linha + movimentos[i][0];
        int nova_coluna = pos.coluna + movimentos[i][1];
        if (nova_linha < 0 || nova_linha >= TAMANHO_TABULEIRO || nova_coluna < 0 || nova_coluna >= TAMANHO_TABULEIRO) break;
        pos.linha = nova_linha;
        pos.coluna = nova_coluna;
        tabuleiro[pos.linha][pos.coluna] = '+';
    }
    tabuleiro[pos.linha][pos.coluna] = simbolo;
}

// ============================================================================
// SEÇÃO 5: FUNÇÕES RECURSIVAS DE MOVIMENTAÇÃO
// ============================================================================

// Função recursiva para simular o movimento da Torre
// Imprime "Direita" para cada casa movida
void mover_torre_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) return;
    printf("Direita\n");
    mover_torre_recursivo(casas_restantes - 1);
}

// Função recursiva para simular o movimento do Bispo
// Imprime "Cima Direita" para cada casa movida
void mover_bispo_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) return;
    printf("Cima Direita\n");
    mover_bispo_recursivo(casas_restantes - 1);
}

// Função recursiva para simular o movimento da Rainha
// Imprime "Esquerda" para cada casa movida
void mover_rainha_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) return;
    printf("Esquerda\n");
    mover_rainha_recursivo(casas_restantes - 1);
}

// ============================================================================
// SEÇÃO 6: FUNÇÕES DE DEMONSTRAÇÃO DE PEÇAS
// ============================================================================

// Demonstração dos movimentos da Torre
// Inicializa tabuleiro, marca movimentos possíveis, executa movimento recursivo e exibe resultado
void mover_torre() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int num_passos = 5;
    Posicao origem = {5, 2}; // C3

    imprimir_separador("MOVIMENTO DA TORRE");
    preparar_tabuleiro(tabuleiro, origem, 'T');
    imprimir_tabuleiro_titulo(tabuleiro, "Torre posicionada em C3:");

    marcar_movimentos(tabuleiro, origem);
    imprimir_tabuleiro_titulo(tabuleiro, "Movimentos possíveis (marcados com *):");

    printf("Movendo a Torre 5 casas para a direita:\n\n");
    mover_torre_recursivo(num_passos);
    printf("\nA Torre se moveu %d casas para a direita.\n", num_passos);

    marcar_caminho_e_posicionar(tabuleiro, origem, 0, 1, num_passos, 'T');
    imprimir_tabuleiro_titulo(tabuleiro, "Tabuleiro após a movimentação (caminho com '+'):");
}

// Demonstração dos movimentos do Bispo
// Usa loops aninhados para simular movimento diagonal
void mover_bispo() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int num_passos = 5;
    Posicao origem = {5, 2}; // c3

    imprimir_separador("MOVIMENTO DO BISPO");
    preparar_tabuleiro(tabuleiro, origem, 'B');
    imprimir_tabuleiro_titulo(tabuleiro, "Bispo posicionado em c3:");

    marcar_movimentos(tabuleiro, origem);
    imprimir_tabuleiro_titulo(tabuleiro, "Movimentos possíveis (marcados com *):");

    printf("Movendo o Bispo 5 casas na diagonal (cima e direita):\n\n");
    for (int v = 0; v < num_passos; v++) {
        for (int h = 0; h < 1; h++) {
            mover_bispo_recursivo(1);
        }
    }
    printf("\nO Bispo se moveu %d casas na diagonal.\n", num_passos);

    marcar_caminho_e_posicionar(tabuleiro, origem, -1, 1, num_passos, 'B');
    imprimir_tabuleiro_titulo(tabuleiro, "Tabuleiro após a movimentação (caminho com '+'):");
}

// Demonstração dos movimentos da Rainha
// Inicializa tabuleiro, marca movimentos possíveis, executa movimento recursivo e exibe resultado
void mover_rainha() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int num_passos = 8;
    Posicao origem = {4, 7}; // H4

    printf("\n=== MOVIMENTO DA RAINHA ===\n");
    preparar_tabuleiro(tabuleiro, origem, 'R');
    imprimir_tabuleiro_titulo(tabuleiro, "Rainha posicionada em H4:");

    marcar_movimentos(tabuleiro, origem);
    imprimir_tabuleiro_titulo(tabuleiro, "Movimentos possíveis (marcados com *):");

    printf("Movendo a Rainha 8 casas para a esquerda:\n\n");
    mover_rainha_recursivo(num_passos);
    printf("\nA Rainha se moveu %d casas para a esquerda.\n", num_passos);

    marcar_caminho_e_posicionar(tabuleiro, origem, 0, -1, num_passos, 'R');
    imprimir_tabuleiro_titulo(tabuleiro, "Tabuleiro após a movimentação (caminho com '+'):");
}

// Demonstração dos movimentos do Cavalo
// Usa loops aninhados e vetor para simular movimento em "L"
void mover_cavalo() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    Posicao origem = {5, 1}; // b3
    int movimentos[3][2] = { {-1,0}, {-1,0}, {0,1} }; // duas para cima, uma para direita

    imprimir_separador("MOVIMENTO DO CAVALO");
    preparar_tabuleiro(tabuleiro, origem, 'C');
    imprimir_tabuleiro_titulo(tabuleiro, "Cavalo posicionado em b3:");

    printf("Movimento em 'L': duas casas para cima e uma para a direita:\n\n");
    printf("Cima\nCima\nDireita\n");

    marcar_caminho_vetor(tabuleiro, origem, movimentos, 3, 'C');
    imprimir_tabuleiro_titulo(tabuleiro, "Tabuleiro após a movimentação (caminho com '+'):");
}

// ============================================================================
// SEÇÃO 7: FUNÇÃO PRINCIPAL
// ============================================================================

// Função principal: executa demonstração dos movimentos das peças
int main() {
    limpar_tela();
    imprimir_separador("SIMULADOR DE MOVIMENTOS DE XADREZ");
    printf("  Desafios: Nível Novato, Aventureiro e Avançado\n");
    printf("\nPressione ENTER para começar...\n");
    getchar();
    limpar_tela();

    mover_torre();
    printf("\nPressione ENTER para continuar...\n");
    getchar();
    limpar_tela();

    mover_bispo();
    printf("\nPressione ENTER para continuar...\n");
    getchar();
    limpar_tela();

    mover_rainha();
    printf("\nPressione ENTER para continuar...\n");
    getchar();
    limpar_tela();

    mover_cavalo();

    imprimir_separador("Fim da demonstração");
    return 0;
}
