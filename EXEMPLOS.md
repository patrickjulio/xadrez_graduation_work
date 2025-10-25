# Exemplos de Movimentação das Peças

Este documento mostra exemplos de como cada peça se movimenta no tabuleiro.

## Torre (Rook)

A Torre move-se horizontalmente e verticalmente, podendo percorrer qualquer número de casas em linha reta.

**Exemplo: Torre em d4**

```
  a b c d e f g h 
8 . . . * . . . . 8
7 . . . * . . . . 7
6 . . . * . . . . 6
5 . . . * . . . . 5
4 * * * T * * * * 4
3 . . . * . . . . 3
2 . . . * . . . . 2
1 . . . * . . . . 1
  a b c d e f g h 
```

Legenda:
- `T` = Torre
- `*` = Movimento possível
- `.` = Casa vazia

### Caminho (+) do programa: C3 → H3 (5 casas para a direita)

```
  a b c d e f g h 
8 . . . . . . . . 8
7 . . . . . . . . 7
6 . . . . . . . . 6
5 . . . . . . . . 5
4 . . . . . . . . 4
3 . . . + + + + T 3
2 . . . . . . . . 2
1 . . . . . . . . 1
  a b c d e f g h 
```

## Bispo (Bishop)

O Bispo move-se diagonalmente, podendo percorrer qualquer número de casas nas diagonais.

**Exemplo: Bispo em e5**

```
  a b c d e f g h 
8 . * . . . . . * 8
7 . . * . . . * . 7
6 . . . * . * . . 6
5 . . . . B . . . 5
4 . . . * . * . . 4
3 . . * . . . * . 3
2 . * . . . . . * 2
1 * . . . . . . . 1
  a b c d e f g h 
```

Legenda:
- `B` = Bispo
- `*` = Movimento possível
- `.` = Casa vazia

### Caminho (+) do programa: c3 → h8 (5 casas na diagonal cima-direita)

```
  a b c d e f g h 
8 . . . . . . . B 8
7 . . . . . . + . 7
6 . . . . . + . . 6
5 . . . . + . . . 5
4 . . . + . . . . 4
3 . . . . . . . . 3
2 . . . . . . . . 2
1 . . . . . . . . 1
  a b c d e f g h 
```

## Rainha (Queen)

A Rainha é a peça mais poderosa, combinando os movimentos da Torre e do Bispo. Pode mover-se horizontalmente, verticalmente e diagonalmente.

**Exemplo: Rainha em d4**

```
  a b c d e f g h 
8 . . . * . . . * 8
7 * . . * . . * . 7
6 . * . * . * . . 6
5 . . * * * . . . 5
4 * * * R * * * * 4
3 . . * * * . . . 3
2 . * . * . * . . 2
1 * . . * . . * . 1
  a b c d e f g h 
```

Legenda:
- `R` = Rainha
- `*` = Movimento possível
- `.` = Casa vazia

### Caminho (+) do programa: h4 → a4 (até a borda à esquerda)

```
  a b c d e f g h 
8 . . . . . . . . 8
7 . . . . . . . . 7
6 . . . . . . . . 6
5 . . . . . . . . 5
4 R + + + + + + . 4
3 . . . . . . . . 3
2 . . . . . . . . 2
1 . . . . . . . . 1
  a b c d e f g h 
```

## Cavalo (Knight)

O Cavalo move-se em "L": duas casas em uma direção (horizontal ou vertical) e depois uma casa perpendicular. Ele é a única peça que pode pular outras peças.

**Exemplo: Cavalo em b3**

```
  a b c d e f g h 
8 . . . . . . . . 8
7 . . . . . . . . 7
6 . . . . . . . . 6
5 * . * . . . . . 5
4 . . . * . . . . 4
3 . C . . . . . . 3
2 . . . * . . . . 2
1 * . * . . . . . 1
  a b c d e f g h 
```

Legenda:
- `C` = Cavalo
- `*` = Movimento possível
- `.` = Casa vazia

### Caminho (+) do programa: b3 → c5 (duas para cima e uma para a direita)

```
  a b c d e f g h 
8 . . . . . . . . 8
7 . . . . . . . . 7
6 . . . . . . . . 6
5 . + C . . . . . 5
4 . + . . . . . . 4
3 . . . . . . . . 3
2 . . . . . . . . 2
1 . . . . . . . . 1
  a b c d e f g h 
```

## Como Usar o Programa

1. Compile e execute o programa.
2. O programa exibirá as demonstrações das peças em sequência (Torre, Bispo, Rainha e Cavalo).
3. Pressione ENTER quando solicitado para avançar para a próxima demonstração.
4. Observe o tabuleiro com a peça posicionada, os movimentos possíveis (`*`) e, quando aplicável, o caminho de um movimento específico (`+`).

## Características do Sistema de Coordenadas

- **Colunas**: Representadas por letras de 'a' a 'h' (da esquerda para a direita)
- **Linhas**: Representadas por números de 1 a 8 (de baixo para cima)
- **Notação**: Sempre coluna + linha (ex: e4, d7, h1)

Este é o sistema padrão de notação algébrica usado no xadrez internacional.
