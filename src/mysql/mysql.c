#include "mysql.h"

passwd * passwords;
int password_count = 0;


void init_databases_menu(void * args) {
  passwd * pass = malloc(sizeof(passwd));
  pass -> host = "127.0.0.1";
  pass -> user = "root";
  pass -> passwd = "";

  addChild((menu_list*)args, createChild("server", &monitor_choose, pass));
}

void print_rows(MYSQL_RES * res) {
  MYSQL_ROW row;
  int fields = mysql_num_fields(res);

  while ((row = mysql_fetch_row(res))) {
    for (int i = 0; i < fields; i++) {
      printf("%s\t", row[i] ? row[i] : "NULL");
    }
    printf("\n");
  }
}

void monitor_choose(void * args) {
  monitor(((passwd*)args) -> host, ((passwd *)args) -> user, ((passwd*)args) -> passwd);  
}

int monitor (char * host, char * user, char * pass) {
  MYSQL * res = mysql_init(NULL);

  if (!(mysql_real_connect(res, host, user, pass, NULL, 0, NULL, 0))) {
    fprintf(stdout, "%s\n", mysql_error(res));
    mysql_close(res);
    return 1;
  }

  printf("We are connected, gays!\n");

  MYSQL_RES * pl = mysql_list_processes(res);
  if (!pl) {
    fprintf(stdout, "%s\n", mysql_error(res));
  }
  else {
    print_rows(pl);
    mysql_free_result(pl);
  }

  if (mysql_query(res, "SHOW SLAVE STATUS")) {
    fprintf(stdout, "%s\n", mysql_error(res));
  }
  else {
    MYSQL_RES * ret = mysql_store_result(res);
    if (!ret) {
      fprintf(stdout, "%s\n", mysql_error(res));
    }
    print_rows(ret);
    mysql_free_result(ret);
  }

  mysql_close(res);
  return 0;
}
