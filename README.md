# xadrez_graduation_work
Meu segundo trabalho da faculdade de engenharia de software. Aqui desenvolvi um programa em C que mostra a movimentação de peças de xadrez, mas não um xadrez completamente funcional.

## Descrição do Projeto

Este projeto implementa a simulação de movimentos de peças de xadrez usando técnicas avançadas de programação em C:

- **Torre**: Movimento recursivo
- **Bispo**: Movimento recursivo e com loops aninhados
- **Rainha**: Movimento recursivo
- **Cavalo**: Movimento com loops complexos em formato "L" (2 casas para cima, 1 para direita)

## Características Implementadas

### Recursividade
- Torre, Bispo e Rainha utilizam funções recursivas para simular seus movimentos
- Cada chamada recursiva representa o movimento para a próxima casa

### Loops Complexos
- **Cavalo**: Utiliza loops aninhados com múltiplas variáveis e condições
- Implementa controle de fluxo com `continue` e `break`
- Simula movimento em "L" característico do cavalo

### Loops Aninhados (Bispo)
- Loop externo controla movimento vertical
- Loop interno controla movimento horizontal
- Implementa movimento diagonal da peça

## Como Compilar e Executar

### Usando Makefile (Recomendado)

```bash
# Compilar o programa
make

# Executar o programa
make run

# Limpar arquivos compilados
make clean

# Recompilar do zero
make rebuild
```

### Compilação Manual

```bash
# Compilar
gcc -Wall -Wextra -std=c99 -o xadrez xadrez.c

# Executar
./xadrez
```

## Estrutura do Código

- `xadrez.c`: Arquivo principal com implementação de todas as peças
- `Makefile`: Arquivo para compilação automatizada
- `.gitignore`: Configuração para ignorar arquivos compilados

## Saída Esperada

O programa imprime a direção do movimento de cada peça:
- `Cima`: movimento para cima
- `Baixo`: movimento para baixo
- `Esquerda`: movimento para esquerda
- `Direita`: movimento para direita

Cada peça tem sua saída separada por uma linha em branco.

## Requisitos

- Compilador GCC
- Sistema operacional compatível com C99 ou superior

## Documentação

O código está completamente documentado com comentários explicando:
- A lógica da recursividade
- O funcionamento dos loops complexos
- O propósito de cada variável e condição
