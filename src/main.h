#ifndef MAIN_H
#define MAIN_H 1

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "mysql/mysql.h"
#include "http/http.h"

void monitor_choose(void * args);
int monitor (char * host, char * user, char * pass);

#endif
