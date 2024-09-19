# Variables
CC = g++
CFLAGS = -Wextra -Wall -std=c++11 -O3
LDFLAGS = -static-libgcc -static-libstdc++ -lpthread -lwinpthread
DEBUGFLAGS = -g
SRC_DIR = src
BUILD_DIR = build/bin
OBJ_DIR = build/obj
INCLUDE_DIR = include
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BUILD_DIR)/cinema.exe

# Regla por defecto
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a archivos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(DEBUGFLAGS) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

# Regla para limpiar archivos generados

clean_obj:
	rm -rf $(OBJ_DIR)

clean: clean_obj
	rm -rf $(BUILD_DIR)

# Regla para recompilar todo desde cero
rebuild: clean all

.PHONY: all clean clean_obj rebuild 
