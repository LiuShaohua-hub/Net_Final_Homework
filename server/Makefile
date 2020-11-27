CC=gcc

DEL=rm

all:server

%.o: %.c %.h
	$(CC) -c *.c

link_op.o: link_op.c link_op.h typess.h
	$(CC) -c *.c

server:userop.o link_op.o server.o 
	$(CC) *.o -o server.out -lpthread

clean:
	$(DEL) *.o *.out