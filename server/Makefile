CC=gcc

DEL=rm

all:server

%.o: %.c %.h
	$(CC) -c *.c

server:server.o userop.o
	$(CC) *.o -o server.out -lpthread

clean:
	$(DEL) *.o *.exe *.out