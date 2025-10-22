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
2. Escolha uma peça (1-Torre, 2-Bispo, 3-Rainha, 0-Sair)
3. Digite a posição desejada no formato de notação algébrica (ex: e4, d5, a1)
4. O programa mostrará o tabuleiro com a peça posicionada e todos os seus movimentos possíveis marcados com *

## Exemplo de Uso

```
Escolha uma peça para demonstrar os movimentos:
1 - Torre
2 - Bispo
3 - Rainha
0 - Sair
Opção: 3

Digite a posição da peça (ex: e4): d4
```

O programa então exibirá o tabuleiro com a Rainha na posição d4 e todos os movimentos possíveis marcados.

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
