OBJS = file.o maze.o stacks.o 
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG)
CFLAGS = -Wall -c $(DEBUG)

maze: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mazeRunner 

file.o: file.cpp file.h
	$(CC) $(CFLAGS) -o file.cpp
maze.o: maze.cpp proto.h 
	$(CC) $(CFLAGS) -o maze.cpp
stacks.o: stacks.cpp stacks.h
	$(CC) $(CFLAGS) -o stacks.cpp

clean: 
	$(RM) maze *.o
