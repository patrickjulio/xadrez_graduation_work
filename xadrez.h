#ifndef XADREZ_H
#define XADREZ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_TABULEIRO 8

// Tipos de peças
typedef enum {
    VAZIO,
    TORRE,
    BISPO,
    RAINHA
} TipoPeca;

// Estrutura para representar uma posição no tabuleiro
typedef struct {
    int linha;
    int coluna;
} Posicao;

// Funções do tabuleiro
void inicializar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void imprimir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void marcar_movimentos(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Posicao origem);

// Funções de validação de movimentos
bool movimento_valido_torre(Posicao origem, Posicao destino);
bool movimento_valido_bispo(Posicao origem, Posicao destino);
bool movimento_valido_rainha(Posicao origem, Posicao destino);

// Funções auxiliares
bool posicao_valida(Posicao pos);
char obter_simbolo_peca(TipoPeca tipo);
const char* obter_nome_peca(TipoPeca tipo);

// Funções de simulação de movimento (Desafio Nível Novato)
void mover_torre();
void mover_bispo();
void mover_rainha();
// Função de simulação de movimento (Desafio Nível Aventureiro)
void mover_cavalo();

#endif
