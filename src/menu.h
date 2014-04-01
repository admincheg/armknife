#ifndef MENU_H
#define MENU_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct menu_list menu_list; 

struct menu_list {
  int count;
  char * name;
  void * arguments;
  void (* func)();
  menu_list * parent;
  menu_list ** childs;
};

menu_list * createChild(char * name, void * func, void * args);
void addChild(menu_list * list, menu_list * added);
void print_menu(menu_list * curr);

#endif
