#ifndef __DATABASS_H__
#define __DATABASS_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sqlite3.h>

#define Databases "msg.db"

#define N 256

void do_sqlite_quit(sqlite3 *db);
void do_sqlite_add(sqlite3 *db,char *name,int data);
void do_sqlite_delete(sqlite3 *db);
void do_sqlite_change(sqlite3 *db);
void do_sqlite_find(sqlite3 *db,char *name);
void do_sqlite_open(sqlite3 **db);

char do_create_table(sqlite3 *db);
int do_callback_find(void *arg,int ncolum,char **f_value,char **f_name);


#endif
