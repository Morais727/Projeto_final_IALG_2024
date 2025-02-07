# Definições do compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lncurses

# Diretórios dos arquivos-fonte
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils

# Lista de arquivos-fonte
SRC = $(SRC_DIR)/main.cpp \
      $(UTILS_DIR)/leCsv.cpp \
      $(UTILS_DIR)/banner.cpp \
      $(UTILS_DIR)/menu1.cpp \
      $(UTILS_DIR)/interactiveMenu.cpp \
      $(UTILS_DIR)/mostrarDetalhesAcomodacao.cpp \
      $(UTILS_DIR)/adicionarRegistro.cpp \
      $(UTILS_DIR)/alteraRegistro.cpp \
      $(UTILS_DIR)/excluirRegistro.cpp \
      $(UTILS_DIR)/imprimeValores.cpp \
      $(UTILS_DIR)/imprimeMenu.cpp \
      $(UTILS_DIR)/carregarBinario.cpp \
      $(UTILS_DIR)/salvarBinario.cpp \
      $(UTILS_DIR)/exportarParaCSV.cpp \
      $(UTILS_DIR)/printSubMenu1.cpp \
      $(UTILS_DIR)/printSubMenu2.cpp \
      $(UTILS_DIR)/printSubMenu3.cpp \
      $(UTILS_DIR)/barraCarregamento.cpp \
      $(UTILS_DIR)/reorganizarIds.cpp\
      $(UTILS_DIR)/verificaEntrada.cpp

# Lista de objetos gerados
OBJ = $(SRC:.cpp=.o)

# Nome do executável
TARGET = sistema_cadastro

# Regra principal
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Regra genérica para compilar os arquivos dentro de src/
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra genérica para compilar os arquivos dentro de src/utils/
$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	@echo "Limpando arquivos compilados..."
	@rm -f $(OBJ) $(TARGET)

# Define alvos que não são arquivos físicos
.PHONY: all clean
