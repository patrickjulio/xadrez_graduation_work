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

1. Execute o programa
2. Escolha uma opção:
   - **Opções 1-3**: Demonstração visual no tabuleiro
   - **Opção 4**: Simulação passo a passo dos movimentos (Desafio Nível Novato)
   - **Opção 0**: Sair
3. Para opções 1-3, digite a posição desejada no formato de notação algébrica (ex: e4, d5, a1)
4. O programa mostrará o tabuleiro com a peça posicionada e todos os seus movimentos possíveis marcados com *

## Desafio: Nível Novato e Aventureiro

O programa inclui implementações especiais dos desafios que demonstram o movimento das peças usando diferentes estruturas de repetição:

- **Torre**: 5 casas para a direita usando estrutura `for`
- **Bispo**: 5 casas na diagonal (cima e direita) usando estrutura `while`
- **Rainha**: 8 casas para a esquerda usando estrutura `do-while`
- **Cavalo**: movimento em "L" (duas casas para baixo e uma para a esquerda) usando loops aninhados (`for` + `while`)

Para acessar esta funcionalidade, escolha a **opção 4** no menu principal.

📄 Consulte [DESAFIO_NOVATO.md](./DESAFIO_NOVATO.md) para mais detalhes sobre a implementação.

## Exemplo de Uso

**Demonstração Visual (Opções 1-3):**
```
Escolha uma opção:
1 - Torre
2 - Bispo
3 - Rainha
4 - Demonstrar movimentos (Desafio Nível Novato)
0 - Sair
Opção: 3

Digite a posição da peça (ex: e4): d4
```

**Simulação de Movimentos (Opção 4):**
```
Escolha uma opção:
1 - Torre
2 - Bispo
3 - Rainha
4 - Demonstrar movimentos (Desafio Nível Novato)
0 - Sair
Opção: 4

=== MOVIMENTO DA TORRE ===
Movendo a Torre 5 casas para a direita:

Direita
Direita
Direita
Direita
Direita

=== MOVIMENTO DO BISPO ===
...

=== MOVIMENTO DA RAINHA ===
...

=== MOVIMENTO DO CAVALO ===
Movendo o Cavalo em 'L': duas casas para baixo e uma para a esquerda:

Baixo
Baixo
Esquerda
```

O programa então exibirá o tabuleiro com a Rainha na posição d4 e todos os movimentos possíveis marcados (opções 1-3), ou a simulação passo a passo dos movimentos (opção 4).

## Requisitos

- Compilador GCC
- Sistema operacional Linux/Unix ou Windows com MinGW
- Make (opcional, para usar o Makefile)

## Funcionalidades

- ✅ Representação visual do tabuleiro 8x8
- ✅ Validação de movimentos da Torre
- ✅ Validação de movimentos do Bispo
- ✅ Validação de movimentos da Rainha
- ✅ Interface interativa de linha de comando
- ✅ Notação algébrica padrão de xadrez (a-h, 1-8)
- ✅ **Simulação de movimentos com estruturas de repetição (`for`, `while`, `do-while`)**

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
