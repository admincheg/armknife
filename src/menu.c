#include "menu.h"

menu_list * createChild(char * name, void * func, void * args) {
  menu_list * list = malloc(sizeof(menu_list));
  list -> childs = NULL;
  list -> parent = NULL;
  list -> name = name;
  list -> count = 0;
  list -> func = func;
  list -> arguments = args;

  return list;
}

void addChild(menu_list * list, menu_list * added) {
  menu_list ** childs = list -> childs;

  menu_list ** new = malloc(sizeof(menu_list*) * (list -> count + 1));
  for (int i = 0; i < list -> count; i++) {
    new[i] = childs[i];
  }
  new[list -> count] = added;

  list -> childs = new;
  list -> count++;
}

void print_menu(menu_list * curr) {
    printf("Current menu: %s\n", curr -> name);

    for (int i = 0; i < curr -> count; i++) {
      printf("%d. %s\n", (i + 1), curr -> childs [i] -> name);
    }
    printf("\n0. Return\n");

    printf("Choose element: ");
}

