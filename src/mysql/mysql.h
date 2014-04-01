#ifndef MYSQL_H
#define MYSQL_H 1

#include <stdio.h>
#include <mysql.h>
#include "../menu.h"

typedef struct passwd {
  char * host;
  char * user;
  char * passwd;
} passwd;


void monitor_choose(void * args);
int monitor (char * host, char * user, char * pass);
void init_databases_menu(void * args);

#endif
