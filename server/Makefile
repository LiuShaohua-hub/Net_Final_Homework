CC=gcc

DEL=rm

all:server

%.o: %.c %.h
	$(CC) -c *.c

#link_op.o: link_op.c link_op.h typess.h
#	$(CC) -c *.c

#server.o:server.c typess.h userop.h link_op.h
#	$(CC) -c *.c 

#userop.o:userop.c userop.h typess.h
#	$(CC) -c *.c

#上面加-lmysqlclient不管用，要在链接的时候加才有用！！！

server:userop.o link_op.o server.o 
	$(CC) *.o -o server.out -lpthread -lmysqlclient

clean:
	$(DEL) *.o *.out