#ifndef _CLIENTOP_H_
#define _CLIENTOP_H_

//这里定义检测到要注册、登录等操作后，做出的动作
void read_id_pwd(int fd,char *buf);

void do_register(int fd,char *buf);

void do_login(int fd,char *buf);

void do_del(int fd,char *buf);

void do_add(int fd,char *buf);

void do_default(int fd,char *buf);

//封装switch  void do_choose_option(int fd,char *buf,int case);

#endif