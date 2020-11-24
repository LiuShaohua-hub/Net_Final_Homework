#include <stdio.h>
#include <string.h>
#include "clientop.h"

void read_id_pwd(int fd,char *buf){
	printf("Please input your ID: ");
	scanf("%s",buf);
	send(fd,buf,sizeof(buf),0);
	memset(buf,0,sizeof(buf));

	printf("Please input your pwd: ");
	scanf("%s",buf);
	send(fd,buf,sizeof(buf),0);
	bzero(buf,sizeof(buf));
}

void do_register(int fd,char *buf){
	printf("do register\n");
	read_id_pwd(fd,buf);
	send(fd,"register",9,0);
	bzero(buf,sizeof(buf));
}

void do_login(int fd,char *buf){
	printf("do login\n");
	read_id_pwd(fd,buf);
	send(fd,"login",6,0);
	bzero(buf,sizeof(buf));
}

void do_del(int fd,char *buf){
	printf("do del\n");
	read_id_pwd(fd,buf);
	send(fd,"del",4,0);
	bzero(buf,sizeof(buf));
}

void do_add(int fd,char *buf){
	printf("do add\n");
	read_id_pwd(fd,buf);
	send(fd,"add",4,0);
	bzero(buf,sizeof(buf));
}

void do_default(int fd,char *buf){
	printf("do nothing\n");
	read_id_pwd(fd,buf);
	send(fd,"do nothing",11,0);
	bzero(buf,sizeof(buf));
}
