#ifndef _USEROP_H_
#define _USEROP_H_

/*
void (* reg)();//char *id, char *pwd)
int (* login)(char id, char pwd);
int (* del)(char id, char pwd);
int (* add)(char id);
*/

//这里是server端的处理函数
int reg(char *id, char *pwd);
int login(char *id, char *pwd);
int del(char *id, char *pwd);
int add(char id);


#endif