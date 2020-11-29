#include "userop.h"
#include "typess.h"
#include "link_op.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define len sizeof(Linklist_User)
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
Linklist_User *head,*p1,*p2;
void visit(int c){
 	 printf("%d ",c);
}
//创建第一个节点，用作链表头部,也即双向链表初始化
int initdlinklist(Linklist_User *head, Linklist_User *tail)
{
    head=(Linklist_User *)malloc(len);
    tail=(Linklist_User *)malloc(len);
    if(!(head)||!(tail))
        return ERROR;
    /*这一步很关键*/ 
    head->pre=NULL;
    tail->next=NULL;
    /*链表为空时让头指向尾*/
    head->next=tail;
    tail->pre=head;
}
/*判定是否为空*/
int emptylinklist(Linklist_User *head,Linklist_User *tail){
    if(head->next==tail)
        return TRUE;
    else
        return FALSE;
} 
/*尾插法创建链表*/ 
int reg(Linklist_User *head,Linklist_User *tail,char *data,char *passwd){
    Linklist_User *pmove=tail,*pinsert;
    pinsert=(Linklist_User *)malloc(len);
    if(!pinsert)
        return ERROR;
    pinsert->id=data;
    pinsert->pwd=passwd;
    pinsert->next=NULL;
    pinsert->pre=NULL;
    tail->pre->next=pinsert;
    pinsert->pre=tail->pre;
    pinsert->next=tail;
    tail->pre=pinsert;
} 
/*正序打印链表*/ 
int traverselist(Linklist_User *head,Linklist_User *tail){
    Linklist_User  *pmove=head->next;
    while(pmove!=tail){
        printf("%d\t",pmove->id);
        pmove=pmove->next;
    }
    printf("\n");
}
/*
int reg(char *id, char *pwd){
	//Linklist_User *t; //用来遍历;
        Linklist_User *user = head;//用来便利linklist的
	while(user!=NULL)
	{
		if(strcmp(user->id,id)==0)
		{
			printf("it has exist！");
			break;
                }

		user = user->next;
	}	
	if(user == NULL)
	{
		int ID = atoi(id);
		if(ID<=0)
		{		
			printf("error\n");
			return 0;
		}
		else
		{
			p1 = (Linklist_User *)malloc(len);
			p1->id = id;
			p1->pwd = pwd;
			p1->message = NULL;
			p1->stat = 0;
			p1->pre = p2;
			p2 = p1;
			p2->next = NULL;
			memset( (void*)p1->friendlist, 0, sizeof(p1->friendlist));
		}
	

	}
//	bianli_c();
//	bianli_c();	
	return 1;
}
*/
/* i* 返回1，找到id pwd匹配的；返回0，登陆失败
*/
int login(char *id, char *pwd){
    printf("here is login\n");
    return 0;
}

int del(char *id, char *pwd){
    printf("here is del\n");
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

