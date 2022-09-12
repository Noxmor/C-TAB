#ifndef CONSOLE_H
#define CONSOLE_H

#include "C-TAB/core/ansi_colors.h"

void console_set_title(const char* title);
void console_clear();
void console_read_input(char* buf, size_t size);
void console_print_seperator();

#endif