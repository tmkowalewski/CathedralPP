OBJS= main.o Board.o
SOURCE	= main.cpp Board.cpp
HEADER	= Board.hpp
OUT	= cathedral.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

.DEFAULT_GOAL := all

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

run:
	$(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp


clean:
	del /f $(OBJS) $(OUT)