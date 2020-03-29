#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pd;

	pd = fork();
	if(pd < 0)
	{
		//失败
		perror("this is error");
		return -1;
	}
	else if(0 == pd)
	{
		client();
	}
	else 
	{
		int ret;
		//父进程
		printf("this is father,%d\r\n",getpid());
		//ret = wait(NULL);
		printf("over %d,\r\n",ret);
	}
	return 0;
}
