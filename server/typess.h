#ifndef _TYPES_H_
#define _TYPES_H_

#include <netinet/in.h>
//这里是各种用到的结构体
//消息结构体
typedef struct mes{
    char id;
    char message[1024];
    struct mes *next;//指向本类型消息指针
}Mes;

//用户结构体
typedef struct user{
    struct user *next;//遍历用户list的指针，指向本类型
    struct user *pre;
    char *id;//回退
    char *pwd;
    int stat;
    char friendlist[128];
    struct mes *message;//指向用户的消息
}Linklist_User;

typedef struct{
	int connectfd;
	struct sockaddr_in client;
}ARG;
#endif
