#include "console.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void console_set_title(const char* title)
{
	char* cmd = malloc((strlen("title ") + strlen(title) + 1) * sizeof(char));
	strcpy(cmd, "title ");
	strcat(cmd, title);
	system(cmd);
	free(cmd);
}

void console_clear()
{
	system("cls");
}

void console_read_input(char* buf, size_t size)
{
	fgets(buf, size, stdin);
}