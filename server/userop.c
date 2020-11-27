#include "userop.h"
#include "typess.h"
#include "link_op.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

extern Linklist_User *head;

void print_all_user_message(){
	Linklist_User *t = head;
	printf("Because Linklist_User is global variable, so this function just print all user message\n");
	while ( t != NULL )
	{
		printf("t->id = %s, t->pwd = %s\n", t->id, t->pwd);//先只是输出id pwd而以
		t = t->next;
	}
}

int reg(char *id, char *pwd){
    Linklist_User *user;//新建一个user用户
    Linklist_User *t = head;//用来便利linklist的
	Linklist_User *end;

    user = (Linklist_User *)malloc(sizeof(Linklist_User));
    user->id = id;
    user->pwd = pwd;//对user的数据进行初始化
	user->next = NULL;//新建的时候next指向的都是NULL
    
    //t指向的node的id大于user当前的id，就需要把user插入到t之前去。
    while ( t != NULL && t->id < user->id ) {
		if( t->next  ==NULL ) end = t;//说明t是最后一个节点，使end指向最后一个node
		t = t->next;
    }

    if( t!= NULL ){
        //说明上面是因为t->id > user->id断掉的，下面要把user插入到t指向的node前面
		t->pre->next = user;
		user->pre = t->pre;
		user->next = t;
		t->pre = user;

        printf("Insert user before pointer t. Here is register,and id = %s, pwd = %s\n",user->id, user->pwd);
        return 1;

        }else{
            //说明上面是因为t == NULL了，所以下面要把user插入到链表最后
            end->next = user;
			user->pre = end;
			user->next = NULL;
            return 1;
        }

}

/*  
* 返回1，找到id pwd匹配的；返回0，登陆失败
*/
int login(char *id, char *pwd){
	Linklist_User *t = head;//用来遍历linklist的
	while( t != NULL){
		//t指向的node不为NULL时，看id域是否与传入的id相等
		if(  atoi(t->id) == atoi(id) && ( strcmp(t->pwd,pwd) ==0 ) ){
			printf("login success !!!\n");
			return 1;
		}
		else {
			//t->id != id ，如果t->next != NULL ,就往后移动一个再来
			if( t->next != NULL ) t = t->next;
			else return 0;//说明t指向最后的node了，且t->id != id，说明链表中始终没有找到与id匹配的，return 0
		}
	}

}

int del(char *id, char *pwd){
	Linklist_User *t = head;//用来遍历linklist的
	/* 第一种方式：
	if( login(id,pwd) ){
		//说明登录成功，id pwd都匹配的上，这里进行【删除node操作】
		return 1;
	}else{
		return 0;//说明返回失败
	}*/
	
	//第二种方式：
	while( t != NULL){
		//t指向的node不为NULL时，看id域是否与传入的id相等
		if(  atoi(t->id) == atoi(id) && ( strcmp(t->pwd,pwd) ==0 ) ){
			printf("begin delete node !!!\n");
			//这里删除t指向的node
			if( t->next == NULL ) {
				t->pre->next  = NULL;
				free(t);
			}//【删除最后一个节点】
			else{
				t->pre->next = t->next;
				t->next->pre = t->pre;
				free(t);//要(void*)吗
			}//删除t指向的node，此node在链表中间
			
			//删除完毕后，输出user的id pwd，再返回
			print_all_user_message();
			return 1;
		}
		else {
			//t->id != id ，如果t->next != NULL ,就往后移动一个再来
			if( t->next != NULL ) t = t->next;
			else return 0;//说明t指向最后的node了，且t->id != id，说明链表中始终没有找到与id匹配的，return 0
		}
	}


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

