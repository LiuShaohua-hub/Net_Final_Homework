#include "userop.h"
#include "typess.h"
#include "link_op.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

extern Linklist_User *head;
extern Linklist_User *node[10];

void print_all_user_message(Linklist_User *h,char *reason){
	Linklist_User *t = h;

	printf("%s, there is print_all_user_message() \n",reason);
	while (  t != NULL )
	{
		printf("t->id = %s, t->pwd = %s\n", t->id, t->pwd);//先只是输出id pwd而以，这里不atoi，就是乱码，atoi了 就是0
		if( t->next != NULL  ) t = t->next;
		else break;
	}

}

void init_one_node(Linklist_User *user, char *id, char *pwd){
	user = (Linklist_User *)malloc(sizeof(Linklist_User));
	user->id = (char*)0;
	user->pwd = "default pwd";
    user->id = id;
    user->pwd = pwd;//对user的数据进行初始化
	user->next = NULL;//新建的时候next指向的都是NULL
	user->message = NULL;
	user->pre = NULL;
	user->stat = 0;
	memset( (void*)user->friendlist, 0, sizeof(user->friendlist));
}

int reg(char *id, char *pwd){
    Linklist_User *user;//新建一个user用户
	Linklist_User *end;
    Linklist_User *t = head;//用来便利linklist的

	user = (Linklist_User *)malloc(sizeof(Linklist_User));
	user->id = (char*)0;
	user->pwd = "default pwd";
    user->id = id;
    user->pwd = pwd;//对user的数据进行初始化
	user->next = NULL;//新建的时候next指向的都是NULL
	user->message = NULL;
	user->pre = NULL;
	user->stat = 0;
	memset( (void*)user->friendlist, 0, sizeof(user->friendlist));
    
	//printf("Here is register,and id = %d, pwd = %d\n",atoi(user->id), atoi( user->pwd) );
/* 第五版，直接先初始化10个node来用，后面再优化。第二个user注册的时候，段错误 
	Linklist_User *new_head = node[0];
	int i = 0;
	for(i = 0; i < 10 ; i++){
		printf("%s ",node[i]->id);
	}
	printf("\n");
	
	while( atoi(new_head->id) != -1 ){
		new_head = new_head->next;
	}
	//new_head指向的node的id是-1，向这个node写入数据
	new_head->id = id;
	new_head->pwd = pwd;
	printf("Here is register,and id = %s, pwd = %s\n",new_head->id,  new_head->pwd );
	//print_all_user_message(node[0],"pre define 10node");
	for(i = 0; i < 10 ; i++){
		printf("%d ",atoi(node[i]->id));
	}
	printf("\n");*/

/* 第四版，进行文件的io 
	FILE *userid_fp,*userpwd_fp;
	userid_fp = fopen("userid.txt","a+");
	userpwd_fp = fopen("userpwd.txt","a+");

	if( userid_fp == NULL ) printf("userid_fp == NULL\n");
	else fprintf(userid_fp,"%d\n", atoi(user->id) );

	if( userpwd_fp == NULL ) printf("userpwd_fp == NULL\n");
	else fprintf(userpwd_fp,"%d\n", atoi(user->pwd) );
	
	printf_txt(userid_fp, userpwd_fp);
	
	fclose(userid_fp);
	fclose(userpwd_fp);
*/

/* 第三版，不管id大小了，直接挂在list最后，，，，，还是不行，之前的自动为0了*/
    while ( t->next != NULL) {
		t = t->next;
    }
	//t->next 为 NULL 了，所以t指向最后一个节点，将user插入到t之后就行
	end = t;
	end->next = user;
	user->pre = end;
	user->next = NULL;
	print_all_user_message(head,"user插入到list最后");
	/* 加下面这一段 代码 直接卡死服务器了，console不停的输出
		t = head;
		while ( t->next !=NULL )
		{
			int count = 0;
			printf("%s ", t->id );
			if(count++ > 10) break;
		}
	*/
	
	return 1;
	//说明t是最后一个节点，使end指向最后一个node，出去马上就是要插入到最后

/* 第二版 ，还是之前的user id 自动变为0
    //t指向的node的id大于user当前的id，就需要把user插入到t之前去。
    while ( atoi( t->id) < atoi(user->id) ) {
		if( t->next  ==NULL ) {
			end = t;
			end->next = user;
			user->pre = end;
			user->next = NULL;
			print_all_user_message("user插入到list最后");
			return 1;
			}//说明t是最后一个节点，使end指向最后一个node，出去马上就是要插入到最后
		t = t->next;
    }

	 if( atoi(t->id) > atoi(user->id)  ){
		t->pre->next = user;
		user->pre = t->pre;
		user->next = t;
		t->pre = user;
		
		print_all_user_message("user 插入到t指向node前面");
        return 1;
	 }else{
		 return 0;
	 }
		*/

/* 第一版 有问题，之前的user id自动变为0了
    if( atoi(t->id) > atoi(user->id)  ){
        //说明上面是因为t->id > user->id断掉的，下面要把user插入到t指向的node前面
		t->pre->next = user;
		user->pre = t->pre;
		user->next = t;
		t->pre = user;
		
		print_all_user_message("user 插入到t指向node前面");
        return 1;
        }else{
            //说明上面是因为t->next = NULL break了，下面要把user插入到链表最后
            end->next = user;
			user->pre = end;
			user->next = NULL;
			print_all_user_message("user插入到list最后");
            return 1;
        }*/

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
			print_all_user_message(head,"登陆成功");
			return 1;
		}
		else {
			//t->id != id ，如果t->next != NULL ,就往后移动一个再来
			if( t->next != NULL ) t = t->next;
			else {
				print_all_user_message(head,"登陆失败");
				return 0;
				}//说明t指向最后的node了，且t->id != id，说明链表中始终没有找到与id匹配的，return 0
		
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
			print_all_user_message(head,"del成功");
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

