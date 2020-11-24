#include <stdio.h>
#include <string.h>
#include "clientop.h"

//读取id发送到服务器 读取pwd然后再发送到服务器
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

//client端的register函数，读取id pwd，然后发送"1"到服务器
void do_register(int fd,char *buf){
	printf("do register(1)\n");
	send(fd,"1",9,0);//先发送action
	read_id_pwd(fd,buf);//再读取id pwd
	bzero(buf,sizeof(buf));
}

//client端的login函数，读取id pwd，然后发送"2"到服务器
void do_login(int fd,char *buf){
	printf("do login(2)\n");
	send(fd,"2",6,0);
	read_id_pwd(fd,buf);
	bzero(buf,sizeof(buf));
}

//client端的del函数，读取id pwd，然后发送"3"到服务器
void do_del(int fd,char *buf){
	printf("do del(3)\n");
	send(fd,"3",4,0);
	read_id_pwd(fd,buf);
	bzero(buf,sizeof(buf));
}

//client端的add函数，读取id pwd，然后发送"4"到服务器
void do_add(int fd,char *buf){
	printf("do add(4)\n");
	send(fd,"4",4,0);
	read_id_pwd(fd,buf);
	bzero(buf,sizeof(buf));
}

//client端的default函数，读取id pwd，然后发送"0"到服务器
void do_default(int fd,char *buf){
	printf("do nothing(0)\n");
	send(fd,"0",11,0);
	read_id_pwd(fd,buf);
	bzero(buf,sizeof(buf));
}
