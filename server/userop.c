#include "userop.h"
#include <stdio.h>

void (* reg)(){
    printf("test\n");
}
/*
int (* login)(char id, char pwd){
    
}
*/
void regg(){
    printf("void regg()\n");
}

int addtwo(int a,int b){
    return a+b;
}