#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void client(void)
{

		//子进程
		printf("this is client,%d\r\n",getpid(),getppid());
		sleep(10);
		printf("time is over\r\n");
		exit(0);
}
