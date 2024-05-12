CC = g++
CFLAGS = -std=c++11 -Wall
SRCS = main.cpp implementacoes/Menu.cpp implementacoes/Astronauta.cpp implementacoes/Voos.cpp implementacoes/ControleTrafego.cpp implementacoes/ControleAstronauta.cpp implementacoes/ControleCadastro.cpp implementacoes/ControleVoos.cpp implementacoes/ControleGeral.cpp
OBJS = $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
EXEC = myprogram

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

obj/%.o: cabecalho/%.cpp cabecalho/Menu.hpp cabecalho/Astronauta.hpp cabecalho/Voos.hpp cabecalho/ControleTrafego.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)