#ifndef _USEROP_H_
#define _USEROP_H_

void print_all_user_message();

//这里是server端的处理函数
int reg(char *id, char *pwd);
int login(char *id, char *pwd);
int del(char *id, char *pwd);
int add();
int sendmessage(char *send_id, char *otherid, char *message);
void default_branch();

#endif