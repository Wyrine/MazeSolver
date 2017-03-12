OBJS = stacks.o file.o maze.o
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG)
CFLAGS = -c

mazeRunner: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mazeRunner

stacks.o: stacks.cpp stacks.h
	$(CC) $(CFLAGS) stacks.cpp
file.o: file.cpp file.h
	$(CC) $(CFLAGS) file.cpp
maze.o: maze.cpp proto.h
	$(CC) $(CFLAGS) maze.cpp

clean:
	$(RM) maze *.o
