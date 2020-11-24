# Net_Final_Homework

### 错误记录
#### Segmentation fault 2020-11-24 16:24
- main开始的时候，加上这一段代码就出错，去掉就是对的？？？？迷惑
```C
	char *id = "my_id";
	char *pwd = "my_pwd";
	int is_register = reg(id,pwd);
	int is_login = login(id,pwd);
	int is_del = del(id,pwd);
	int is_add = add('a');
```

#### field ‘client’ has incomplete type 2020-11-24 16:39
- 应该就是头文件没有引入

#### makefile make: *** [a.o] Error 1 2020-11-24 20:32
- linux下的makefile里rm *.exe了，不是在windows下，所以删去就好了
- 没有要删除的文件的时候，也会错误，空删

### 进度记录
- 2020-11-24 20:56---->client 根据argv[2]的值1-4判断要干什么，然后发送action，读取id发送id 读pwd，发pwd(相应server，先接受action，然后根据action判断调用哪个业务函数)
- 2020-11-24 22::20---->添加了发送信息的框架，拿到信息后怎么处理待写