#include <pthread.h>
#include "my.h"
#define filename "/dev/ap3216c"

void *iic_run(void *reg)
{
	int fd;
	unsigned short databuf[3];
	unsigned short ir, als, ps;
	int ret = 0;


	fd = open(filename, O_RDWR);
	if(fd < 0) {
		printf("can't open file %s\r\n", filename);
	pthread_exit(NULL);
	}

	while (1) {
		ret = read(fd, databuf, sizeof(databuf));
		if(ret == 0) { 			/* 数据读取成功 */
			ir =  databuf[0]; 	/* ir传感器数据 */
			als = databuf[1]; 	/* als传感器数据 */
			ps =  databuf[2]; 	/* ps传感器数据 */
			printf("ir = %d, als = %d, ps = %d\r\n", ir, als, ps);
		}
		sleep(2); /*100ms */
	}
	close(fd);	/* 关闭文件 */	
	pthread_exit(NULL);
}
