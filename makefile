CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lncurses
SRC = src/main.cpp src/utils/banner.cpp src/utils/leituraCSV.cpp src/utils/menu_1.cpp src/utils/menu_2.cpp src/utils/menus_interativos.cpp src/utils/mostra_detalhes.cpp src/utils/adiciona_registro.cpp src/utils/altera_registro.cpp src/utils/exclui_registro.cpp src/utils/imprime_informacoes.cpp src/utils/imprime_menu.cpp src/utils/carrega_binario.cpp src/utils/salvar_binario.cpp src/utils/sub_menu_1.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = sistema_cadastro

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
