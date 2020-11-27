#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
/*
int reg(char *id, char *pwd){

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
}
*/

void printf_txt(FILE *fp){
	char idLine[1024];
	char ch;	
    while ( !feof(fp) )//(ch=fgetc(fp)) != EOF 
	{        
		fgets(idLine, 10, fp);
		printf("id = %s ", idLine);
	}
}

int main(){
	FILE *userid_fp,*userpwd_fp;
	userid_fp = fopen("userid.txt","rw+");
	userpwd_fp = fopen("userpwd.txt","rw+");

    if( userid_fp == NULL ) printf("userid_fp == NULL\n");
    else{
        printf_txt(userid_fp);
    }

	if( userpwd_fp == NULL ) printf("userpwd_fp == NULL\n");
    else{

    }


	fclose(userid_fp);
	fclose(userpwd_fp);
    return 0;
}