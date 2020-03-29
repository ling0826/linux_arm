#ifndef __MY_H__
#define __MY_H__

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sqlite3.h>
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "sys/ioctl.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"
#include <poll.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>

pthread_t thread_iic;
pthread_t thread_spi;

void* spi_run(void *reg);
void *iic_run(void *reg);

#endif

