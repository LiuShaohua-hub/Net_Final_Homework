#ifndef _LINK_OP_H_
#define _LINK_OP_H_

#include "typess.h"

//这里是对Linlist_User的链表操作
Linklist_User *creat_linklist(int n);

void change_node(Linklist_User *list,int n);

void delet_node(Linklist_User *list, int n);

void insert_node(Linklist_User *list, int n);


#endif