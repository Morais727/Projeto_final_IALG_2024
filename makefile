CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = src/main.cpp src/utils/banner.cpp src/utils/leituraCSV.cpp src/utils/menu_1.cpp src/utils/menu_2.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = sistema_cadastro

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
