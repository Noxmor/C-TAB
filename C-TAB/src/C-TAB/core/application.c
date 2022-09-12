#include "application.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "C-TAB/core/console.h"
#include "C-TAB/core/input.h"

static void cmd_quit(Application* app)
{
	application_stop(app);
}

static void update_loading_state()
{
	console_print_seperator();
	printf("Please specify the game directory to load.\n");
	console_print_seperator();
}

static void update_main_state()
{
	console_print_seperator();
	printf("Main menu\n");
	console_print_seperator();
}

static void update_options_state()
{
	console_print_seperator();
	printf("Options menu\n");
	console_print_seperator();
}

static bool str_is_digits(const char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '\n')
			continue;
		
		if (str[i] < 0 || !isdigit(str[i]))
			return false;
	}

	return true;
}

static void application_init(Application* app)
{
	console_set_title(app->title);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < MAX_COMMANDS; j++)
		{
			app->menus[i].commands[j].type = CMD_INVALID;
		}
	}

	app->menus[GAMESTATE_LOADING_MENU].update_fn = update_loading_state;

	app->menus[GAMESTATE_LOADING_MENU].commands[0].display_name = "Test dir";
	app->menus[GAMESTATE_LOADING_MENU].commands[0].type = CMD_CHANGE_MENU;
	app->menus[GAMESTATE_LOADING_MENU].commands[0].menu_id = GAMESTATE_MAIN_MENU;

	app->menus[GAMESTATE_LOADING_MENU].commands[1].display_name = "Game dir";
	app->menus[GAMESTATE_LOADING_MENU].commands[1].type = CMD_CHANGE_MENU;
	app->menus[GAMESTATE_LOADING_MENU].commands[1].menu_id = GAMESTATE_MAIN_MENU;

	app->menus[GAMESTATE_LOADING_MENU].commands[2].display_name = "Dir dir";
	app->menus[GAMESTATE_LOADING_MENU].commands[2].type = CMD_CHANGE_MENU;
	app->menus[GAMESTATE_LOADING_MENU].commands[2].menu_id = GAMESTATE_MAIN_MENU;

	app->menus[GAMESTATE_LOADING_MENU].commands[3].display_name = "Quit";
	app->menus[GAMESTATE_LOADING_MENU].commands[3].type = CMD_QUIT;

	app->menus[GAMESTATE_MAIN_MENU].update_fn = update_main_state;

	app->menus[GAMESTATE_MAIN_MENU].commands[0].display_name = "Options";
	app->menus[GAMESTATE_MAIN_MENU].commands[0].type = CMD_CHANGE_MENU;
	app->menus[GAMESTATE_MAIN_MENU].commands[0].menu_id = GAMESTATE_OPTIONS_MENU;

	app->menus[GAMESTATE_MAIN_MENU].commands[1].display_name = "Quit";
	app->menus[GAMESTATE_MAIN_MENU].commands[1].type = CMD_QUIT;

	app->menus[GAMESTATE_OPTIONS_MENU].update_fn = update_options_state;

	app->menus[GAMESTATE_OPTIONS_MENU].commands[0].display_name = "Back";
	app->menus[GAMESTATE_OPTIONS_MENU].commands[0].type = CMD_CHANGE_MENU;
	app->menus[GAMESTATE_OPTIONS_MENU].commands[0].menu_id = GAMESTATE_MAIN_MENU;
}

Application* application_create(const char* title)
{
	Application* app = malloc(sizeof(Application));
	app->title = title;
	app->state = GAMESTATE_LOADING_MENU;
	return app;
}

void application_run(Application* app)
{
	app->running = true;

	application_init(app);

	char buffer[12];
	memset(buffer, 0, 12);

	uint8_t cmd_id = 0;

	while (app->running)
	{
		console_clear();

		app->menus[app->state].update_fn();

		menu_print_commands(&app->menus[app->state]);

		console_read_input(buffer, 12);

		if (!str_is_digits(buffer))
			continue;

		cmd_id = atoi(buffer);
		if (cmd_id < 1 || cmd_id > MAX_COMMANDS)
			continue;

		Command* cmd = &app->menus[app->state].commands[cmd_id - 1];
		
		switch (cmd->type)
		{
			case CMD_QUIT:
				application_stop(app);
				break;

			case CMD_CHANGE_MENU:
				app->state = cmd->menu_id;
				break;
		}
	}
}

void application_stop(Application* app)
{
	app->running = false;
}