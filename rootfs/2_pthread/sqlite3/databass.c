#include "databass.h"

char sql[N] = {0};
unsigned int id; 			//编号
char name[N] = {0};  		//姓名
unsigned int  socre; 		//分数 
char *errmsg; 		//错误信息
char flag = 0;

void do_sqlite_open(sqlite3 **db)
{
	if(SQLITE_OK != sqlite3_open(Databases,db))
	{
		printf("sqlite3_open error : %s",sqlite3_errmsg(*db));
		exit(0);
	}
	//打开/创建数据表
	
	

}
//创建数据表（根据实际使用修改）
char do_create_table(sqlite3 *db)
{
	//创建一个表存储历史记录
	sprintf(sql,"create table history(name text,time text,num char);");
	//执行一条sql语句达到创建一个表
	if(SQLITE_OK !=sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		if(116 != *errmsg)
		{
			printf("sqlite3_exec1 error : %s",errmsg);
			printf("---------------\n");
		}
		else
		printf("数据库中的 history 打开成功\n");
	}
	else
		printf("create table stuinfo sucess\n");

	//创建一个表存储用户信息
	sprintf(sql,"create table stuinfo(name text,num integer);");

	//执行一条sql语句达到创建一个表
	if(SQLITE_OK !=sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		if(116 != *errmsg)
		{
			printf("sqlite3_exec1 error : %s",errmsg);
			printf("---------------\n");
		}
		else
		printf("数据库中的 stuinfo 打开成功\n");
	}
	else
		printf("create table stuinfo sucess\n");
}

//退出 
void do_sqlite_quit(sqlite3 *db)
{
	//关闭信息描述符
	sqlite3_close(db);
	printf("quit...\n");
	exit(0);
}

void do_sqlite_add(sqlite3 *db,char* name,int data)
{
/*
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
*/
	//生成sql指令
	sprintf(sql,"insert into stuinfo values('%s',%d);",name,data);


	//执行一条sql语句达到添加信息的功能
	if(SQLITE_OK !=sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec add1 error : %s",errmsg);
	}
	struct tm *tp;
	time_t ti;
	char time1[64] = {0};
	time(&ti);
	tp = localtime(&ti);
	sprintf(time1,"%d-%d-%d %d:%d:%d",tp->tm_year+1900,tp->tm_mon+1,\
			tp->tm_mday,tp->tm_hour,tp->tm_min,tp->tm_sec);


	//生成sql指令
	sprintf(sql,"insert into history values('%s','%s',%d);",name,time1,data);


	//执行一条sql语句达到添加信息的功能
	if(SQLITE_OK !=sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec add2 error : %s",errmsg);
	}
	printf("do_sqlite_add sucess\n");

}

void do_sqlite_delete(sqlite3 *db)
{
	char delid[N] = {0};
	do_sqlite_find(db,NULL);
	printf("输入需要删除的数据的id>>>");
	scanf("%s",delid);
	getchar();
	
		sprintf(sql,"delete from stuinfo where id=%s;",delid);

	//执行一条sql语句
	if(SQLITE_OK !=sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec error  in do_sqlite_delete: %s",errmsg);
	}
	else
	{
		printf("do_sqlite_add sucess in do_sqlite_delete\n");
	}
}
void do_sqlite_change(sqlite3 *db)
{
	char local_id[N] = {0};
	char local_title[N] = {0};
	char local_result[N] = {0};
	printf("输入要替换数据所在组的id>>>>");
	fgets(local_id,N,stdin);
	local_id[strlen(local_id) - 1] = '\0';
	printf("输入要替换的名称(id/name/socre)");		
	fgets(local_title,N,stdin);
	local_title[strlen(local_title) - 1] = '\0';
	printf("输入要替换的结果");		
	fgets(local_result,N,stdin);
	local_result[strlen(local_result) - 1] = '\0';

	if(0 == strncmp(local_title,"name",4))
		sprintf(sql,"update stuinfo set %s = '%s' where id = %s ",local_title,local_result,local_id);
	else
		sprintf(sql,"update stuinfo set %s = %s where id = %s ",local_title,local_result,local_id);

	//执行一条sql语句
	if(SQLITE_OK !=sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec error  in do_sqlite_change: %s",errmsg);
	}
	else
	{
		printf("do_sqlite_add sucess in do_sqlite_change\n");
	}

}
void do_sqlite_find(sqlite3 *db,char *name)
{
	sprintf(sql,"select * from history where name = '%s';",name);


	//执行一条sql语句
	if(SQLITE_OK !=sqlite3_exec(db,sql,do_callback_find,NULL,&errmsg))
	{
		printf("sqlite3_exec error : %s",errmsg);
	}
	else
	{
		printf("do_sqlite_add sucess\n");
	}
	flag = 0;

}
int do_callback_find(void *arg,int ncolum,char **f_value,char **f_name)
{
	int i = 0;
	if(0 == flag)
	{
		for(i = 0; i < ncolum; i++)
			printf("%-20s",f_name[i]);
		printf("\n********************************************************************\n");
		flag = 1;
	}
	for(i = 0; i < ncolum; i++)
	{
		printf("%-20s",f_value[i]);
	}
	printf("\n");
	return 0;
}

