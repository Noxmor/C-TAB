#include "menu.h"

#include <stdio.h>

void menu_print_commands(Menu* menu)
{
	int cmdCounter = 1;
	for (int i = 0; i < MAX_COMMANDS; i++)
	{
		if (menu->commands[i].type == CMD_INVALID)
			continue;

		printf("[%d] %s\n", cmdCounter++, menu->commands[i].display_name);
	}
}