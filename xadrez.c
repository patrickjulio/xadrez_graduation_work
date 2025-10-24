#include "xadrez.h"

// Inicializa o tabuleiro vazio
void inicializar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

// Imprime a linha de colunas (a-h)
static void imprimir_linha_colunas() {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

// Imprime o tabuleiro
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

// Verifica se uma posição é válida no tabuleiro
bool posicao_valida(Posicao pos) {
    return pos.linha >= 0 && pos.linha < TAMANHO_TABULEIRO &&
           pos.coluna >= 0 && pos.coluna < TAMANHO_TABULEIRO;
}

// Retorna o símbolo da peça
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

// Valida movimento da Torre (horizontal ou vertical)
bool movimento_valido_torre(Posicao origem, Posicao destino) {
    return (origem.linha == destino.linha && origem.coluna != destino.coluna) ||
           (origem.coluna == destino.coluna && origem.linha != destino.linha);
}

// Valida movimento do Bispo (diagonal)
bool movimento_valido_bispo(Posicao origem, Posicao destino) {
    int diff_linha = abs(destino.linha - origem.linha);
    int diff_coluna = abs(destino.coluna - origem.coluna);
    return diff_linha == diff_coluna && diff_linha > 0;
}

// Valida movimento da Rainha (horizontal, vertical ou diagonal)
bool movimento_valido_rainha(Posicao origem, Posicao destino) {
    return movimento_valido_torre(origem, destino) ||
           movimento_valido_bispo(origem, destino);
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

// Valida movimento baseado no tipo de peça
static bool validar_movimento(TipoPeca tipo, Posicao origem, Posicao destino) {
    switch (tipo) {
        case TORRE:   return movimento_valido_torre(origem, destino);
        case BISPO:   return movimento_valido_bispo(origem, destino);
        case RAINHA:  return movimento_valido_rainha(origem, destino);
        default:      return false;
    }
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

// Limpa o buffer de entrada
static void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Limpa a tela do terminal
static void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Lê a opção do menu
static int ler_opcao_menu() {
    int opcao;
    printf("Escolha uma opção:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Demonstrar movimentos (Desafios Novato e Aventureiro)\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    
    if (scanf("%d", &opcao) != 1) {
        limpar_buffer();
        return -1;
    }
    limpar_buffer();
    return opcao;
}

// Lê a posição da peça
static Posicao ler_posicao() {
    char coluna_char;
    int linha_num;
    Posicao pos;
    
    do {
        printf("\nDigite a posição da peça:");
        printf("\n  - Colunas: de 'a' até 'h'");
        printf("\n  - Linhas: de 1 até 8");
        printf("\n  - Formato: letra + número (ex: e4)");
        printf("\nPosição: ");
        
        if (scanf(" %c%d", &coluna_char, &linha_num) != 2) {
            printf("\nEntrada inválida! Tente novamente.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();
        
        pos.coluna = coluna_char - 'a';
        pos.linha = 8 - linha_num;
        
        if (!posicao_valida(pos)) {
            printf("\nPosição inválida! Use colunas 'a'-'h' e linhas 1-8.\n");
        }
    } while (!posicao_valida(pos));
    
    return pos;
}

// Converte opção do menu para tipo de peça
static TipoPeca opcao_para_tipo(int opcao) {
    switch (opcao) {
        case 1: return TORRE;
        case 2: return BISPO;
        case 3: return RAINHA;
        default: return VAZIO;
    }
}

// Simula o movimento da Torre usando estrutura for
// Move 5 casas para a direita
void mover_torre() {
    int casas_a_mover = 5; // Número de casas definido no código
    
    printf("\n=== MOVIMENTO DA TORRE ===\n");
    printf("Movendo a Torre 5 casas para a direita:\n\n");
    
    // Utiliza estrutura de repetição FOR para simular o movimento
    for (int casa = 1; casa <= casas_a_mover; casa++) {
        printf("Direita\n");
    }
    
    printf("\nA Torre se moveu %d casas para a direita.\n", casas_a_mover);
}

// Simula o movimento do Bispo usando estrutura while
// Move 5 casas na diagonal (cima e direita)
void mover_bispo() {
    int casas_a_mover = 5; // Número de casas definido no código
    int casa = 1; // Contador de casas percorridas
    
    printf("\n=== MOVIMENTO DO BISPO ===\n");
    printf("Movendo o Bispo 5 casas na diagonal (cima e direita):\n\n");
    
    // Utiliza estrutura de repetição WHILE para simular o movimento diagonal
    while (casa <= casas_a_mover) {
        printf("Cima Direita\n");
        casa++;
    }
    
    printf("\nO Bispo se moveu %d casas na diagonal.\n", casas_a_mover);
}

// Simula o movimento da Rainha usando estrutura do-while
// Move 8 casas para a esquerda
void mover_rainha() {
    int casas_a_mover = 8; // Número de casas definido no código
    int casa = 1; // Contador de casas percorridas
    
    printf("\n=== MOVIMENTO DA RAINHA ===\n");
    printf("Movendo a Rainha 8 casas para a esquerda:\n\n");
    
    // Utiliza estrutura de repetição DO-WHILE para simular o movimento
    do {
        printf("Esquerda\n");
        casa++;
    } while (casa <= casas_a_mover);
    
    printf("\nA Rainha se moveu %d casas para a esquerda.\n", casas_a_mover);
}

// Simula o movimento do Cavalo usando loops aninhados (for + while)
// Movimento em "L": duas casas para baixo e uma para a esquerda
// Saída esperada: "Baixo", "Baixo", "Esquerda"
void mover_cavalo() {
    // Quantidades definidas diretamente no código, conforme requisitos
    int passos_verticais = 2;   // duas casas para baixo
    int passos_horizontais = 1; // uma casa para a esquerda

    // Mensagens de direção (strings literais)
    const char* direcao_vertical = "Baixo";
    const char* direcao_horizontal = "Esquerda";

    printf("\n=== MOVIMENTO DO CAVALO ===\n");
    printf("Movendo o Cavalo em 'L': duas casas para baixo e uma para a esquerda:\n\n");

    // Loop externo (for): itera pelas fases do movimento (0 = vertical, 1 = horizontal)
    for (int fase = 0; fase < 2; fase++) {
        // Define quantos passos fazer na fase atual
        int passos = (fase == 0) ? passos_verticais : passos_horizontais;

        // Loop interno (while): executa os passos da fase atual
        int contador = 0;
        while (contador < passos) {
            if (fase == 0) {
                printf("%s\n", direcao_vertical);   // imprime "Baixo"
            } else {
                printf("%s\n", direcao_horizontal); // imprime "Esquerda"
            }
            contador++;
        }
    }
}

// Demonstra os movimentos de uma peça
static void demonstrar_movimentos(TipoPeca tipo, Posicao pos) {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    limpar_tela();
    
    inicializar_tabuleiro(tabuleiro);
    tabuleiro[pos.linha][pos.coluna] = obter_simbolo_peca(tipo);
    
    char coluna_char = 'a' + pos.coluna;
    int linha_num = 8 - pos.linha;
    
    printf("\n%s posicionada em %c%d:\n", obter_nome_peca(tipo), coluna_char, linha_num);
    imprimir_tabuleiro(tabuleiro);
    
    marcar_movimentos(tabuleiro, pos);
    
    printf("Movimentos possíveis (marcados com *):\n");
    imprimir_tabuleiro(tabuleiro);
    
    printf("Legenda:\n");
    printf("  %c = %s\n", obter_simbolo_peca(tipo), obter_nome_peca(tipo));
    printf("  * = Movimento possível\n");
    printf("  . = Casa vazia\n\n");
    
    printf("Pressione ENTER para continuar...");
    getchar();
}

int main() {
    limpar_tela();
    
    printf("===========================================\n");
    printf("  JOGO DE XADREZ - MOVIMENTAÇÃO DE PEÇAS\n");
    printf("===========================================\n\n");
    
    while (true) {
        int opcao = ler_opcao_menu();
        
        if (opcao == -1) {
            printf("\nEntrada inválida! Tente novamente.\n\n");
            continue;
        }
        
        if (opcao == 0) {
            limpar_tela();
            printf("\nEncerrando o programa...\n");
            break;
        }
        
        // Opção 4: Demonstrar movimentos dos desafios (Novato e Aventureiro)
        if (opcao == 4) {
            limpar_tela();
            printf("===========================================\n");
            printf("  DESAFIOS: NÍVEL NOVATO E AVENTUREIRO\n");
            printf("  Movimentando as Peças do Xadrez\n");
            printf("===========================================\n");
            
            // Simula movimento da Torre usando FOR
            mover_torre();
            printf("\nPressione ENTER para continuar...");
            getchar();
            
            // Simula movimento do Bispo usando WHILE
            mover_bispo();
            printf("\nPressione ENTER para continuar...");
            getchar();
            
            // Simula movimento da Rainha usando DO-WHILE
            mover_rainha();
            printf("\nPressione ENTER para continuar...");
            getchar();

            // Simula movimento do Cavalo usando loop aninhado (FOR + WHILE)
            // Separado por uma linha em branco (garantida pelo início da função)
            mover_cavalo();
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();
            
            limpar_tela();
            printf("===========================================\n");
            printf("  JOGO DE XADREZ - MOVIMENTAÇÃO DE PEÇAS\n");
            printf("===========================================\n\n");
            continue;
        }
        
        if (opcao < 1 || opcao > 4) {
            printf("\nOpção inválida! Escolha entre 0 e 4.\n\n");
            continue;
        }
        
        TipoPeca tipo = opcao_para_tipo(opcao);
        Posicao pos = ler_posicao();
        demonstrar_movimentos(tipo, pos);
        
        limpar_tela();
        printf("===========================================\n");
        printf("  JOGO DE XADREZ - MOVIMENTAÇÃO DE PEÇAS\n");
        printf("===========================================\n\n");
    }
    
    return 0;
}
