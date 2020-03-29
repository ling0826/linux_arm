#include "my.h"



extern pthread_t thread_iic;
extern pthread_t thread_spi;

int main(int args,char* argv[])
{
	int ret;
	ret = pthread_create(&thread_iic,NULL,iic_run, NULL);
	if(ret != 0)
	{
		printf("pthread_create is error \r\n");
		return -1;
	}
	ret = pthread_create(&thread_spi,NULL,spi_run, NULL);
	if(ret != 0)
	{
		printf("pthread_create 2 is error \r\n");
		return -1;
	}
	pthread_join(thread_iic,NULL);
	pthread_join(thread_spi,NULL);
	printf("over \r\n");
	return 0;
}
