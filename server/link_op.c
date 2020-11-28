#include "link_op.h"
#include "typess.h"
#include <stdlib.h>
#include <stddef.h>//包含了NULL

/*
* 创建包含n个User的链表
* 
*/
Linklist_User *creat_linklist(int n){
    Linklist_User *head, *node, *end;//定义头节点指针，普通节点指针，尾部节点指针；
    head = (Linklist_User*)malloc(sizeof(Linklist_User));//给head节点分配地址
    end = head;//若是空链表则头尾节点一样
    int i = 0;         
    for (i = 0; i < n; i++) {
        node = (Linklist_User*)malloc(sizeof(Linklist_User));
        //scanf("%d", &node->score);对链表中的域进行初始化
        end->next = node;//这里其实就是head->next = node，将head的next指向新建的node节点
        end = node;//然后end指向这个新挂上去的node，直到最后一个循环，就是指向最后一个node的指针
    }
    end->next = NULL;//结束创建，将指向最后一个node的节点指针指向的节点的next域，置NULL，
    return head;//返回create的链表的头
}

/*
* 传入链表head指针，修改第n个node
* 
*/
void change_node(Linklist_User *list,int n) {
    Linklist_User *t = list;
    int i = 0;

    while (i < n && t != NULL) {
        t = t->next;
        i++;
    }
    
    if (t != NULL) {
        //这里进行node的修改
        //puts("输入要修改的值");
        //scanf("%d", &t->score);
    }else {
        puts("node not exist");
    }
}

/*
* 传入链表head指针，删除第n个node
* 
*/
void delet_node(Linklist_User *list, int n) {
    Linklist_User *t = list, *in;
    int i = 0;
    while (i < n && t != NULL) {
        in = t;
        t = t->next;
        i++;
    }
    if (t != NULL) {
        in->next = t->next;
        free(t);
    }
    else {
        puts("node not exist");
    }
}

/*
* 输入链表head指针，在位置n插入node
* 
*/
void insert_node(Linklist_User *list, int n) {
    Linklist_User *t = list, *in;
    int i = 0;
    while (i < n && t != NULL) {
        t = t->next;
        i++;
    }
    if (t != NULL) {
        in = (Linklist_User*)malloc(sizeof(Linklist_User));

        //这里对要修改的域进行修改
        //puts("输入要插入的值");
        //scanf("%d", &in->score);
        
        in->next = t->next;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
        t->next = in;//填充t节点的指针域，把t的指针域重新指向in
    }
    else {
        puts("node not exist");
    }    
}
