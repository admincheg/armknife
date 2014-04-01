#ifndef HTTP_H
#define HTTP_H

#include <stdio.h>
#include <arpa/inet.h>

#include "../menu.h"

typedef struct {
  struct in_addr host;
  int count;
} ping_host;

void init_http_menu(menu_list * parent);
void ping_client(void * args);

#endif
