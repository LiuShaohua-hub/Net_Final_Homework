CC=gcc

DEL=rm

all:client

%.o: %.c %.h
	$(CC) -c *.c

client:clientop.o client.o
	$(CC) *.o -o client.out 

clean:
	$(DEL) *.o *.exe *.out