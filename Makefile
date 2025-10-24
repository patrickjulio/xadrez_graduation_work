# Makefile para o programa de xadrez

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
TARGET = xadrez

# Arquivo fonte
SRC = xadrez.c

# Regra padrão
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Regra para limpar arquivos compilados
clean:
	rm -f $(TARGET)

# Regra para recompilar
rebuild: clean all

.PHONY: all run clean rebuild
