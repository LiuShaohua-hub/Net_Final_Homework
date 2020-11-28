#ifndef _USEROP_H_
#define _USEROP_H_

#include "typess.h"
void print_all_user_message(Linklist_User *h,char *reason);
void init_one_node(Linklist_User *user, char *id, char *pwd);
//这里是server端的处理函数
int reg(char *id, char *pwd);
int login(char *id, char *pwd);
int del(char *id, char *pwd);
int add();
int sendmessage(char *send_id, char *otherid, char *message);
void default_branch();

#endif
