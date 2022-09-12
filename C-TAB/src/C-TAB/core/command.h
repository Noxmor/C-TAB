#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>

enum CommandType
{
	CMD_INVALID = 0,
	CMD_QUIT,
	CMD_CHANGE_MENU
};

typedef struct
{
	const char* display_name;
	uint8_t type;
	uint8_t menu_id;
} Command;

#endif