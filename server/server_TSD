#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define PORT 12345
#define MAXDATASIZE 100
#define BACKLOG 5
typedef struct{
	int connectfd;
	struct sockaddr_in client;
}ARG;

static pthread_key_t Key;
int err;
static pthread_once_t  once = PTHREAD_ONCE_INIT;

void destr(void *arg){
	printf("destroy memory, pthread_self is %ld\n\n",pthread_self());
	free(arg);
}

void thread_init(){
	pthread_key_create(&Key,destr);
}

void reverseString(char* s, int sSize){
    int i = 0;
    char temp;
    sSize-=1;
    while(i < sSize)
    {
        temp = *(s+i);
        *(s+i) = *(s+sSize);
        *(s+sSize) = temp;
        i++;
        sSize--;
    }
}

void read_input(int connectfd,int *numbytes,char *namebuffer,char *recvbuffer){
	printf("等待输入姓名\n");
	if( (*numbytes = recv(connectfd,namebuffer,MAXDATASIZE,0)) == -1  ){
		perror("recv error.");
		exit(1);
	}
	namebuffer[*numbytes] = '\0';
	printf("thread %ld recv name : %s\n",pthread_self(),namebuffer);
	//上面的sizeof问题还是没解决


	printf("等待输入信息\n");
	if( (*numbytes = recv(connectfd,recvbuffer,MAXDATASIZE,0)) == -1  ){
		perror("recv error.");
		exit(1);

	}
	recvbuffer[*numbytes] = '\0';
	printf("thread %ld recv message : %s\n",pthread_self(),recvbuffer);
}

void process_cli(int connectfd,struct sockaddr_in client){
	char sendbuffer[MAXDATASIZE];
	char recvbuffer[MAXDATASIZE];
	char namebuffer[MAXDATASIZE];
	int numbytes;
	
	read_input(connectfd,&numbytes,namebuffer,recvbuffer);

	//第一次调用的人，必须给TSD创建key
	pthread_once(&once,thread_init);

	void *data;
	data = pthread_getspecific(Key);
	if(data == NULL){
		data = malloc(sizeof(char)*(numbytes+1));
		pthread_setspecific(Key,(void*)data);
	}

	printf("thread %ld before cpy is %s\n",pthread_self(),(char*)pthread_getspecific(Key));
	
	//memcpy之后应该就算是修改data中的数据了，所以下面的changedata等于没用
	memcpy(data,recvbuffer,sizeof(char)*(numbytes+1));
	
	printf("thread(from main) %ld is running, and data after memcpy(before reverse) is %s\n",pthread_self(),(char*)pthread_getspecific(Key));

	//输入边界的问题，只要翻转的边界合适，就能正常输出，numbytes是1024，不是真正有数据的大小
	reverseString(recvbuffer,strlen(recvbuffer));


	printf("recvbuffer after reverse is %s\n",recvbuffer);

	send(connectfd,recvbuffer,sizeof(recvbuffer),0);

}

void *start_routine(void *arg){
	ARG *info;
	info = (ARG*)arg;
	printf("This is pthread_creat server,!!!!!start_routine here server-end!!!!!,you got a connection form %s ,and port is %d\n",inet_ntoa((info->client).sin_addr),htons((info->client).sin_port));
//	send(info->connectfd,"You got a TCP connection",25,0);

	process_cli(info->connectfd,info->client);

	pthread_exit(NULL);
}

void input(int connectfd,struct sockaddr_in client){
	send(connectfd,"Please input your name:",24,0);
//	recv(connectfd,);
}

int main()
{
    pid_t pid;
	int sockfd,connectfd;
    struct sockaddr_in server, client;
    socklen_t sin_size;
	pthread_t tid;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            printf("Create socket failed.");
            exit(1);
    }
	int opt = SO_REUSEADDR;
	setsockopt(sockfd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
            perror("Bind error.");
            exit(1);
    }
	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen error.");
		exit(-1);
	}
	sin_size = sizeof(client);

	err = pthread_key_create(&Key,destr);

	while(1){
		ARG *arg;

		if ((connectfd = accept(sockfd, (struct sockaddr *)&client, &sin_size)) == -1) {
		perror("accept error.");
		exit(-1);
		}
		
		arg->connectfd = connectfd;
		//先取arg指向的client，再取地址，再强转为指向void指针
		memcpy((void*)&arg->client,&client,sizeof(client));

		if( (pthread_create(&tid,NULL,start_routine,(void*)arg)) ){
			printf("pthread_creat error\n");
			exit(1);
		}

	}

}
