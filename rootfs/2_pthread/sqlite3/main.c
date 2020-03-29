#include <stdio.h>
#include "databass.h"


int main()
{
	sqlite3 *dp;
	do_sqlite_open(&dp);
	do_create_table(dp);
	do_sqlite_add(dp,"123",458);
	do_sqlite_quit(dp);
}
