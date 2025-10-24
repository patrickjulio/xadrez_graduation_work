/*
 * Programa de Xadrez - Movimentos de Peças
 * 
 * Este programa simula os movimentos das seguintes peças de xadrez:
 * - Torre (Rook): movimento recursivo
 * - Bispo (Bishop): movimento recursivo e com loops aninhados
 * - Rainha (Queen): movimento recursivo
 * - Cavalo (Knight): movimento com loops complexos em "L"
 * 
 * Autor: Sistema de Xadrez
 * Data: 2025
 */

#include <stdio.h>

// Constantes para definir o número de casas a serem movidas
#define CASAS_TORRE 5
#define CASAS_BISPO 4
#define CASAS_RAINHA 6
#define CASAS_CAVALO_VERTICAL 2
#define CASAS_CAVALO_HORIZONTAL 1

/*
 * Função recursiva para movimento da Torre
 * A Torre se move em linha reta (horizontal ou vertical)
 * 
 * Parâmetros:
 * - casas: número de casas restantes a serem movidas
 * - direcao: string com a direção do movimento
 */
void movimentoTorreRecursivo(int casas, const char* direcao) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    // Imprime a direção do movimento
    printf("%s\n", direcao);
    
    // Chamada recursiva para a próxima casa
    movimentoTorreRecursivo(casas - 1, direcao);
}

/*
 * Função recursiva para movimento do Bispo
 * O Bispo se move em diagonal
 * 
 * Parâmetros:
 * - casas: número de casas restantes a serem movidas
 * - direcaoVertical: direção vertical do movimento
 * - direcaoHorizontal: direção horizontal do movimento
 */
void movimentoBispoRecursivo(int casas, const char* direcaoVertical, const char* direcaoHorizontal) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    // Imprime as direções do movimento diagonal
    printf("%s\n", direcaoVertical);
    printf("%s\n", direcaoHorizontal);
    
    // Chamada recursiva para a próxima casa
    movimentoBispoRecursivo(casas - 1, direcaoVertical, direcaoHorizontal);
}

/*
 * Função com loops aninhados para movimento do Bispo
 * Loop externo controla movimento vertical
 * Loop interno controla movimento horizontal
 * 
 * Parâmetros:
 * - casas: número de casas a serem movidas
 * - direcaoVertical: direção vertical do movimento
 * - direcaoHorizontal: direção horizontal do movimento
 */
void movimentoBispoLoops(int casas, const char* direcaoVertical, const char* direcaoHorizontal) {
    int i, j;
    
    // Loop externo: movimento vertical
    for (i = 0; i < casas; i++) {
        printf("%s\n", direcaoVertical);
        
        // Loop interno: movimento horizontal
        for (j = 0; j < 1; j++) {
            printf("%s\n", direcaoHorizontal);
        }
    }
}

/*
 * Função recursiva para movimento da Rainha
 * A Rainha combina movimentos da Torre e do Bispo
 * Neste exemplo, ela se move em diagonal
 * 
 * Parâmetros:
 * - casas: número de casas restantes a serem movidas
 * - direcaoVertical: direção vertical do movimento
 * - direcaoHorizontal: direção horizontal do movimento
 */
void movimentoRainhaRecursivo(int casas, const char* direcaoVertical, const char* direcaoHorizontal) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    // Imprime as direções do movimento
    printf("%s\n", direcaoVertical);
    printf("%s\n", direcaoHorizontal);
    
    // Chamada recursiva para a próxima casa
    movimentoRainhaRecursivo(casas - 1, direcaoVertical, direcaoHorizontal);
}

/*
 * Função com loops complexos para movimento do Cavalo
 * O Cavalo se move em "L": 2 casas para cima e 1 para a direita
 * Utiliza loops aninhados com múltiplas variáveis e condições
 * Usa continue e break para controle de fluxo
 * 
 * Parâmetros:
 * - casasVerticais: número de casas verticais (2 para cima)
 * - casasHorizontais: número de casas horizontais (1 para direita)
 */
void movimentoCavaloComplexo(int casasVerticais, int casasHorizontais) {
    int i, j;
    int contadorVertical = 0;
    int contadorHorizontal = 0;
    
    // Loop externo: controla o movimento vertical (2 casas para cima)
    for (i = 0; i < casasVerticais; i++) {
        // Verifica se já completou o movimento vertical
        if (contadorVertical >= casasVerticais) {
            break; // Interrompe o loop se já moveu todas as casas verticais
        }
        
        // Imprime o movimento para cima
        printf("Cima\n");
        contadorVertical++;
        
        // Após mover verticalmente, verifica se deve mover horizontalmente
        // Loop interno: controla o movimento horizontal após as movimentações verticais
        for (j = 0; j <= casasHorizontais; j++) {
            // Se ainda não completou o movimento vertical, continua
            if (contadorVertical < casasVerticais) {
                continue; // Pula para a próxima iteração sem mover horizontalmente ainda
            }
            
            // Se já tentou mover horizontalmente, sai do loop
            if (contadorHorizontal >= casasHorizontais) {
                break; // Interrompe o loop horizontal
            }
            
            // Imprime o movimento para a direita
            printf("Direita\n");
            contadorHorizontal++;
        }
    }
    
    // Se ainda falta movimento horizontal após o loop externo
    if (contadorHorizontal < casasHorizontais) {
        for (j = contadorHorizontal; j < casasHorizontais; j++) {
            printf("Direita\n");
        }
    }
}

/*
 * Função principal
 * Executa os movimentos de todas as peças
 */
int main() {
    // Movimento da Torre (Recursivo)
    printf("Torre:\n");
    movimentoTorreRecursivo(CASAS_TORRE, "Direita");
    printf("\n"); // Linha em branco para separar
    
    // Movimento do Bispo (Recursivo)
    printf("Bispo (Recursivo):\n");
    movimentoBispoRecursivo(CASAS_BISPO, "Cima", "Direita");
    printf("\n"); // Linha em branco para separar
    
    // Movimento do Bispo (Loops Aninhados)
    printf("Bispo (Loops Aninhados):\n");
    movimentoBispoLoops(CASAS_BISPO, "Cima", "Direita");
    printf("\n"); // Linha em branco para separar
    
    // Movimento da Rainha (Recursivo)
    printf("Rainha:\n");
    movimentoRainhaRecursivo(CASAS_RAINHA, "Cima", "Direita");
    printf("\n"); // Linha em branco para separar
    
    // Movimento do Cavalo (Loops Complexos)
    printf("Cavalo:\n");
    movimentoCavaloComplexo(CASAS_CAVALO_VERTICAL, CASAS_CAVALO_HORIZONTAL);
    printf("\n"); // Linha em branco para separar
    
    return 0;
}
