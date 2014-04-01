#include "main.h"

menu_list * root; 

int main(int argc, char ** argv) {

  root = createChild("Root", NULL, NULL);

  menu_list * databases = createChild("Databases", NULL, NULL);
  init_databases_menu(databases);
  addChild(root, databases);

  menu_list * http = createChild("Http tools", NULL, NULL);
  init_http_menu(http);
  addChild(root, http);

  menu_list * current_menu = root;

  print_menu(current_menu);

  int ch = 0;
  int ret = 1;
  /*int len = 0;
  char * buff = malloc(sizeof(char) * 255);*/
  while (1) {

    /*buff[0] = 0;
    len = 0;
    ch = getchar();
    while (len < 255 && ch != '\n'){
      if (ch < '0' || ch > '9') {
        ret = 0;
        break;
      }

      buff[len] = ch;
      buff[len + 1] = 0;
      len++;
      ret = 1;
      ch = getchar();
    }

    ch = atoi(buff);
    printf("Value %d\n", atoi(buff));*/
    ret = scanf("%d", &ch);
    while (getchar() != '\n');

    printf("\n");

    if (ret != 1) {
      printf("Wrong choise\n\n");
      print_menu(current_menu);
      continue;
    }


    if (ch == 0 && current_menu -> parent == NULL) {
      break;
    }

    if (ch == 0) {
      current_menu = current_menu -> parent;
    }

    if (ch > 0 && ch <= current_menu -> count) {
      ch--;

      if (current_menu -> childs[ch] -> func != NULL) {
        printf("Result:\n\n");
        for (int i = 0; i < 80; i++) {
          printf("-");
        }
        printf("\n");
        (current_menu -> childs[ch] -> func)( current_menu -> childs[ch] -> arguments );
        for (int i = 0; i < 80; i++) {
          printf("-");
        }
        printf("\n\n");
      }
      else {
        current_menu -> childs[ch] -> parent = current_menu;

        current_menu = current_menu -> childs[ch];
      }
    }

    print_menu(current_menu);
  }

  return 0;
}

