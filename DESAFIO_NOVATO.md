# Desafio: Nível Novato - Movimentando as Peças do Xadrez

## Descrição

Este programa implementa a simulação de movimento de três peças de xadrez (Torre, Bispo e Rainha) utilizando diferentes estruturas de repetição em C.

## Implementação

### 1. Torre - Estrutura `for`
**Movimento:** 5 casas para a direita

```c
void mover_torre() {
    int casas_a_mover = 5; // Número de casas definido no código
    
    // Utiliza estrutura de repetição FOR para simular o movimento
    for (int casa = 1; casa <= casas_a_mover; casa++) {
        printf("Direita\n");
    }
}
```

**Justificativa:** A estrutura `for` é ideal quando sabemos exatamente quantas iterações serão necessárias. Neste caso, 5 casas para a direita.

### 2. Bispo - Estrutura `while`
**Movimento:** 5 casas na diagonal (cima e direita)

```c
void mover_bispo() {
    int casas_a_mover = 5; // Número de casas definido no código
    int casa = 1; // Contador de casas percorridas
    
    // Utiliza estrutura de repetição WHILE para simular o movimento diagonal
    while (casa <= casas_a_mover) {
        printf("Cima Direita\n");
        casa++;
    }
}
```

**Justificativa:** A estrutura `while` testa a condição antes de executar o bloco, sendo adequada para quando precisamos verificar uma condição antes de cada movimento.

### 3. Rainha - Estrutura `do-while`
**Movimento:** 8 casas para a esquerda

```c
void mover_rainha() {
    int casas_a_mover = 8; // Número de casas definido no código
    int casa = 1; // Contador de casas percorridas
    
    // Utiliza estrutura de repetição DO-WHILE para simular o movimento
    do {
        printf("Esquerda\n");
        casa++;
    } while (casa <= casas_a_mover);
}
```

**Justificativa:** A estrutura `do-while` garante que o bloco seja executado pelo menos uma vez antes de testar a condição, simulando o movimento da peça que sempre faz pelo menos um movimento.

## Como Executar

1. Compile o programa:
```bash
make
```

2. Execute o programa:
```bash
./xadrez
```

3. No menu, escolha a opção 4 - "Demonstrar movimentos (Desafio Nível Novato)"

## Saída Esperada

```
===========================================
  DESAFIO: NÍVEL NOVATO
  Movimentando as Peças do Xadrez
===========================================

=== MOVIMENTO DA TORRE ===
Movendo a Torre 5 casas para a direita:

Direita
Direita
Direita
Direita
Direita

A Torre se moveu 5 casas para a direita.

=== MOVIMENTO DO BISPO ===
Movendo o Bispo 5 casas na diagonal (cima e direita):

Cima Direita
Cima Direita
Cima Direita
Cima Direita
Cima Direita

O Bispo se moveu 5 casas na diagonal.

=== MOVIMENTO DA RAINHA ===
Movendo a Rainha 8 casas para a esquerda:

Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda
Esquerda

A Rainha se moveu 8 casas para a esquerda.
```

## Requisitos Atendidos

### Requisitos Funcionais ✓
- ✓ Entrada de Dados: Valores definidos em variáveis/constantes no código
- ✓ Lógica de Movimentação: Cada peça implementa seu movimento específico
- ✓ Saída de Dados: Utiliza printf com o padrão especificado

### Requisitos Não Funcionais ✓
- ✓ Performance: Código eficiente sem atrasos perceptíveis
- ✓ Documentação: Código comentado explicando cada parte
- ✓ Legibilidade: Código organizado, claro e com nomes descritivos
- ✓ Tipos de Variáveis: Utiliza apenas tipos inteiros (int)

## Estruturas de Dados Utilizadas

- **int**: Para contadores e número de casas a serem movidas
- **Strings literais**: Para as mensagens de direção (printf)

## Observações

O programa também mantém as funcionalidades anteriores:
- Opções 1, 2, 3: Demonstração visual dos movimentos possíveis no tabuleiro
- Opção 4: Nova funcionalidade que atende ao desafio (simulação passo a passo)
- Opção 0: Sair do programa
