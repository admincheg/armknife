#include "http.h"

void init_http_menu(menu_list * parent) {
  addChild(parent, createChild("Destination ping", &ping_client, NULL));
}

void ping_client(void * args) {

  ping_host * ph = malloc(sizeof(ping_host));
  char * host;
  host = malloc(sizeof(char)*255);

  printf("Ip address: ");
  scanf("%s", host);
  if (!inet_aton(host, &(ph -> host))) {
    printf("Wrong ip adress! Try again\n");
  }
  else {
    printf("Count pings: ");
    int ret = scanf("%d", &(ph -> count));
    if (ret != 1) {
      printf("Wrong count of pings. Range is [0, ..., positive infinity]\n");
    }
    else {
      printf("We have parameters!\nIp: %s\nCount: %d\n", inet_ntoa(ph -> host), ph -> count);
    }

    printf("Ret is %d\n", ret);
  }
}
