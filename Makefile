CC = g++
CFLAGS = -std=c++11 -Wall
SRCS = main.cpp Menu.cpp Astronauta.cpp Voos.cpp ControleTrafego.cpp ControleAstronauta.cpp ControleCadastro.cpp ControleVoos.cpp ControleGeral.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = myprogram

all: $(EXEC)

$(EXEC):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp Menu.hpp Astronauta.hpp Voos.hpp ControleTrafego.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)