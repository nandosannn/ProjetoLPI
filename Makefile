CC = g++
CFLAGS = -std=c++11 -Wall
SRCS = main.cpp Menu.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = myprogram

all: $(EXEC)

$(EXEC):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp Menu.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)