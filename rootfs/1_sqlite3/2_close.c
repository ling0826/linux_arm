#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#define PATHNAME "msg.db"

int main(int args,char* argv[])
{
	int ret;
	sqlite3 *pd;
	ret = sqlite3_open(PATHNAME,&pd);
	if(0 != ret)
	{
		printf("sqlite3_open is error\r\n");
	}
	else
		printf("ret = %d\r\n",ret);
	
	ret = sqlite3_close(&pd);
	if(0 != ret)
	{
		printf("sqlite3_close is error\r\n");
	}
	else
		printf("ret = %d\r\n",ret);
	return 0;
	
}

