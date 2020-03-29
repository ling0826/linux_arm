#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#define PATHNAME "msg.db"

int main(int args,char* argv[])
{
	int ret;
	sqlite3 *pd;
	char *errmsg;
	char sql[128];
	signed int id; 			//编号
	char name[10] = {0};  		//姓名
	unsigned int  socre; 		//分数 
	ret = sqlite3_open(PATHNAME,&pd);
	if(0 != ret)
	{
		printf("sqlite3_open is error\r\n");
	}
	else
		printf("ret = %d\r\n",ret);

	//增加信息
	//ret = sqlite3_exec(pd,sql,NULL,NULL,&errmsg);

	//输入相关信息
	printf("输入你要添加的信息>>>>\n");
	printf("input id>>>>");
	scanf("%d",&id);
	getchar();

	printf("input name>>>>");
	scanf("%s",name);
	getchar();

	printf("input socre>>>>");
	scanf("%d",&socre);
	getchar();

	//生成sql指令
	sprintf(sql,"create table stuinfo(id integer, name text, socre integer);");


	//执行一条sql语句达到添加信息的功能
	if(SQLITE_OK !=sqlite3_exec(pd,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec error : %s",errmsg);
	}



	//生成sql指令
	sprintf(sql,"insert into stuinfo values(%d,'%s',%d);",id,name,socre);


		printf("ret = %d,***********sql = %s\r\n",ret,sql);
	//执行一条sql语句达到添加信息的功能
	if(SQLITE_OK !=sqlite3_exec(pd,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec error : %s",errmsg);
	}
	printf("do_sqlite_add sucess\n");

	ret = sqlite3_close(pd);
	if(0 != ret)
	{
		printf("sqlite3_close is error\r\n");
	}
	else
		printf("ret = %d,sql = %s\r\n",ret,sql);
	return 0;

}

