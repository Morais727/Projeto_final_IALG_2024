CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lncurses
SRC = src/main.cpp src/utils/banner.cpp src/utils/leituraCSV.cpp src/utils/menu_1.cpp src/utils/menu_2.cpp src/utils/menus_interativos.cpp src/utils/mostra_detalhes.cpp src/utils/banner_casa.cpp src/utils/adiciona_registro.cpp src/utils/altera_registro.cpp src/utils/exclui_registro.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = sistema_cadastro

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
