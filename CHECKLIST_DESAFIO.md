# Checklist - Desafio Nível Novato

## ✅ Requisitos Funcionais

### Entrada de Dados
- [x] Valores definidos diretamente no código através de variáveis
  - `int casas_a_mover = 5;` (Torre)
  - `int casas_a_mover = 5;` (Bispo)
  - `int casas_a_mover = 8;` (Rainha)

### Lógica de Movimentação
- [x] Torre: Move 5 casas para a direita usando `for`
  ```c
  for (int casa = 1; casa <= casas_a_mover; casa++) {
      printf("Direita\n");
  }
  ```

- [x] Bispo: Move 5 casas na diagonal (cima e direita) usando `while`
  ```c
  while (casa <= casas_a_mover) {
      printf("Cima Direita\n");
      casa++;
  }
  ```

- [x] Rainha: Move 8 casas para a esquerda usando `do-while`
  ```c
  do {
      printf("Esquerda\n");
      casa++;
  } while (casa <= casas_a_mover);
  ```

### Saída de Dados
- [x] Impressão da direção a cada casa percorrida
- [x] Uso de `printf()` conforme especificado
- [x] Padrão de saída seguido:
  - `printf("Direita\n");` ✓
  - `printf("Cima Direita\n");` ✓
  - `printf("Esquerda\n");` ✓

## ✅ Requisitos Não Funcionais

### Performance
- [x] Código eficiente
- [x] Execução sem atrasos perceptíveis
- [x] Uso adequado de estruturas de repetição

### Documentação
- [x] Código comentado explicando cada função
- [x] Comentários sobre as estruturas de repetição utilizadas
- [x] Documentação adicional em DESAFIO_NOVATO.md
- [x] README.md atualizado com instruções

### Legibilidade
- [x] Código claro e organizado
- [x] Nomes de variáveis descritivos:
  - `casas_a_mover` - número de casas a percorrer
  - `casa` - contador de casas percorridas
- [x] Indentação adequada
- [x] Estrutura modular (funções separadas)

### Tipos de Variáveis
- [x] Uso exclusivo de variáveis inteiras (`int`)
- [x] Strings literais para mensagens (conforme permitido)

## 📊 Estruturas de Repetição

| Peça    | Estrutura  | Movimento                    | Casas |
|---------|------------|------------------------------|-------|
| Torre   | `for`      | Direita                      | 5     |
| Bispo   | `while`    | Diagonal (Cima e Direita)    | 5     |
| Rainha  | `do-while` | Esquerda                     | 8     |

## 🎯 Objetivo Alcançado

O programa simula corretamente o movimento das três peças de xadrez usando estruturas de repetição diferentes, imprimindo a direção do movimento a cada casa percorrida, conforme especificado no desafio.

## 🚀 Como Testar

```bash
# Compilar
make

# Executar
./xadrez

# Escolher opção 4 no menu
# Pressionar ENTER para ver cada movimento
```

## 📝 Notas Adicionais

- O programa mantém as funcionalidades originais (opções 1-3)
- A nova funcionalidade (opção 4) foi integrada ao menu existente
- Código segue boas práticas de programação em C
- Implementação modular facilita manutenção e extensão
