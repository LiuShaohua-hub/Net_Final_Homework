#ifndef _USEROP_H_
#define _USEROP_H_
/*
void (* reg)();//char *id, char *pwd)
int (* login)(char id, char pwd);
int (* del)(char id, char pwd);
int (* add)(char id);
*/

int reg(char *id, char *pwd);
int login(char *id, char *pwd);
int del(char *id, char *pwd);
int add(char id);

int addtwo(int a,int b);
void regg();

#endif