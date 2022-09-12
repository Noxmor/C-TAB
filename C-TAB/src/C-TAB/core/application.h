#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdbool.h>
#include <stdint.h>

#include "C-TAB/core/menu.h"

#define MAX_MENUS 3

enum GameState
{
	GAMESTATE_LOADING_MENU = 0,
	GAMESTATE_MAIN_MENU,
	GAMESTATE_OPTIONS_MENU
};

typedef struct
{
	const char* title;
	bool running;
	Menu menus[MAX_MENUS];
	uint8_t state;
} Application;

Application* application_create(const char* title);
void application_run(Application* app);
void application_stop(Application* app);

#endif