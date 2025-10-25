# xadrez_graduation_work
Meu segundo trabalho da faculdade de engenharia de software. Aqui desenvolvi um programa em C que mostra a movimentação de peças de xadrez, mas não um xadrez completamente funcional.

## Descrição

Este programa demonstra a movimentação de três peças de xadrez:
- **Torre**: Move-se horizontalmente e verticalmente
- **Bispo**: Move-se diagonalmente
- **Rainha**: Move-se horizontalmente, verticalmente e diagonalmente (combina Torre e Bispo)

## Estrutura do Projeto

- `xadrez.h` - Arquivo de cabeçalho com definições de estruturas e protótipos de funções
- `xadrez.c` - Implementação principal do programa
- `Makefile` - Arquivo para compilação automatizada

## Como Compilar

```bash
make
```

Para limpar os arquivos compilados:
```bash
make clean
```

## Como Executar

```bash
./xadrez
```

Ou diretamente com:
```bash
make run
```

## Como Usar

1. Execute o programa: `./xadrez`
2. O programa executará automaticamente a demonstração completa das 4 peças em sequência:
    - **Torre**: Tabuleiro gráfico + movimentos possíveis + 5 movimentos para direita
    - **Bispo**: Tabuleiro gráfico + movimentos possíveis + 5 movimentos diagonal
    - **Rainha**: Tabuleiro gráfico + movimentos possíveis + 8 movimentos para esquerda
    - **Cavalo**: Tabuleiro gráfico + movimento em L (2 baixo + 1 esquerda)
3. Pressione ENTER entre cada demonstração para avançar

## Desafio: Nível Novato e Aventureiro

O programa demonstra o movimento das peças usando diferentes estruturas de repetição. Cada peça é apresentada com:
1. **Visualização gráfica** do tabuleiro 8x8 com a peça posicionada
2. **Movimentos possíveis** marcados com asterisco (*)
3. **Simulação passo a passo** imprimindo cada direção do movimento

### Estruturas de Repetição Utilizadas:
- **Torre**: 5 casas para a direita usando estrutura `for`
- **Bispo**: 5 casas na diagonal (cima e direita) usando estrutura `while`
- **Rainha**: 8 casas para a esquerda usando estrutura `do-while`
- **Cavalo**: movimento em "L" (duas casas para baixo e uma para a esquerda) usando loops aninhados (`for` + `while`)

📄 Consulte [DESAFIO_NOVATO.md](./DESAFIO_NOVATO.md) para mais detalhes sobre a implementação.

## Exemplo de Uso

```
$ ./xadrez

===========================================
   DESAFIOS: NÍVEL NOVATO E AVENTUREIRO
   Movimentando as Peças do Xadrez
===========================================

=== MOVIMENTO DA TORRE ===
Torre posicionada em d4:

   a b c d e f g h 
8 . . . . . . . . 8
7 . . . . . . . . 7
...
4 . . . T . . . . 4
...

Movimentos possíveis (marcados com *):

   a b c d e f g h 
...
4 * * * T * * * * 4
...

Movendo a Torre 5 casas para a direita:

Direita
Direita
Direita
Direita
Direita
...
```

A demonstração continua automaticamente para as outras três peças (Bispo, Rainha e Cavalo).

## Requisitos

- Compilador GCC
- Sistema operacional Linux/Unix ou Windows com MinGW
- Make (opcional, para usar o Makefile)

## Funcionalidades

- ✅ Representação visual do tabuleiro 8x8
- ✅ Validação de movimentos da Torre
- ✅ Validação de movimentos do Bispo
- ✅ Validação de movimentos da Rainha
- ✅ Notação algébrica padrão de xadrez (a-h, 1-8)
- ✅ **Simulação de movimentos com estruturas de repetição (`for`, `while`, `do-while`)**
- ✅ **Demonstração automática e sequencial** das 4 peças com tabuleiro gráfico
- ✅ **Loops aninhados** para movimento do Cavalo em "L"

## Estruturas de Repetição Utilizadas

Este projeto demonstra o uso das três principais estruturas de repetição em C:

1. **`for`** - Movimento da Torre (5 casas para a direita)
   - Ideal quando o número de iterações é conhecido
   
2. **`while`** - Movimento do Bispo (5 casas na diagonal)
   - Testa a condição antes de cada iteração
   
3. **`do-while`** - Movimento da Rainha (8 casas para a esquerda)
   - Executa o bloco pelo menos uma vez antes de testar a condição

4. **Loops aninhados (`for` + `while`)** - Movimento do Cavalo (duas para baixo, uma para a esquerda)
   - Um loop controla a fase (vertical/horizontal) e o outro executa os passos
