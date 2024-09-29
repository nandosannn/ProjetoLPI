# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Diretórios
SRC_DIR = src
MODEL_SRC_DIR = $(SRC_DIR)/model

# Arquivos fonte
SOURCES = Main.cpp \
          $(MODEL_SRC_DIR)/Astronauta.cpp \
          $(MODEL_SRC_DIR)/ControleAstronauta.cpp \
          $(MODEL_SRC_DIR)/ControleCadastro.cpp \
          $(MODEL_SRC_DIR)/ControleGeral.cpp \
          $(MODEL_SRC_DIR)/ControleTrafego.cpp \
          $(MODEL_SRC_DIR)/ControleVoos.cpp \
          $(MODEL_SRC_DIR)/Menu.cpp \
          $(MODEL_SRC_DIR)/Voos.cpp

# Arquivos objeto correspondentes (cada .cpp gera um .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Nome do executável
EXEC = programa

# Regra padrão: compilar o projeto
all: $(EXEC)

# Linkar os arquivos objeto para criar o executável
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

# Regra para compilar os arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJECTS) $(EXEC)

# Phony targets
.PHONY: all clean
