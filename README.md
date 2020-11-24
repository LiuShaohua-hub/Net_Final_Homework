# Net_Final_Homework

### 错误记录
#### Segmentation fault 2020-11-24 16:24
- main加上这一段代码就出错，去掉就是对的？？？？迷惑
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