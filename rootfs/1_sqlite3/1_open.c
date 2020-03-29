#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#define PATHNAME "msg.db"

int main(int args,char* argv[])
{
	int ret;
	sqlite3 *pd;
	ret = sqlite3_open(PATHNAME,&pd);
	printf("ret = %d\r\n",ret);
}

