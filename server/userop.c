#include "userop.h"
#include "typess.h"
#include <stdio.h>

int reg(char *id, char *pwd){
    /*
    User user;
    user.id = id;
    user.pwd = pwd;*/
    printf("here is register,and id = %s, pwd = %s\n",id, pwd);
    return 1;
}

int login(char *id, char *pwd){
    printf("here is login,and id = %s, pwd = %s\n",id,pwd);
    return 0;
}

int del(char *id, char *pwd){
    printf("here is del,and id = %s, pwd = %s\n",id,pwd);
    return 0;
}

int add(){
    printf("here is add\n");
    return 0;
}

int sendmessage(char *send_id, char *otherid, char *message){
    printf("from id = %s to id = %s and send message = %s\n",send_id,otherid,message);
}

void default_branch(){
    printf("here is default branch\n");
}