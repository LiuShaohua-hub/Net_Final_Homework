#include "userop.h"
#include "typess.h"
#include "link_op.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define len sizeof(Linklist_User)
extern Linklist_User *head,*p1,*p2;

//创建第一个节点，用作链表头部，但不存储有用信息
void creatfirst()
{
	head = p1 = p2 = (Linklist_User *)malloc(sizeof(Linklist_User));
	p1->id = "-1";
	p1->pwd = "sjwsw";
	p1->pre = NULL;
	p2->next = NULL;
}


int reg(char *id, char *pwd){
	//Linklist_User *t; //用来遍历;
        Linklist_User *user = head;//用来便利linklist的
	while(1)
	{
		user = user->next;
		if(user !=NULL&&strcmp(user->id,id)==0)
		{
			printf("it has exist！");
			break;
                }
		else if(user == NULL)
		{
			int ID = atoi(id);
			if(ID<=0)
			{
				printf("error\n");
				break;
			}
			else{
				p1 = (Linklist_User *)malloc(len);
				p1->id = id;
				p1->pwd = pwd;
				p1->message = NULL;
				p1->stat = 0;
				p1->pre = p2;
				p2 = p1;
				p2->next = NULL;
				memset( (void*)user->friendlist, 0, sizeof(user->friendlist));
			}
		}
	}
	return 1;
}

/*  
* 返回1，找到id pwd匹配的；返回0，登陆失败
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

