#ifndef _TYPES_H_
#define _TYPES_H_

#include <netinet/in.h>
//这里是各种用到的结构体
//消息结构体
typedef struct {
    char id;
    char message[1024];
    struct Mes *p_message;//指向本类型消息指针
}Mes;

//用户结构体
typedef struct {
    struct User *p_userlist;//遍历用户list的指针，指向本类型
    char *id;
    char *pwd;
    int stat;
    char friendlist[128];
    struct Mes *p_umessage;//指向用户的消息
}User;

typedef struct{
	int connectfd;
	struct sockaddr_in client;
}ARG;

#endif