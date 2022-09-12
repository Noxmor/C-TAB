#ifndef MENU_H
#define MENU_H

#include "C-TAB/core/command.h"

#define MAX_COMMANDS 10

typedef struct
{
	void (*update_fn)();
	Command commands[MAX_COMMANDS];
} Menu;

void menu_print_commands(Menu* menu);

#endif