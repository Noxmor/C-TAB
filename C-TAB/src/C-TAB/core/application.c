#include "application.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "C-TAB/core/console.h"
#include "C-TAB/core/input.h"

static void application_init(Application* app)
{
	console_set_title(app->title);
}

Application* application_create(const char* title)
{
	Application* app = malloc(sizeof(Application));
	app->title = title;
	return app;
}

void application_run(Application* app)
{
	app->running = true;

	application_init(app);

	char buffer[12];

	while (app->running)
	{
		console_clear();

		//update logic

		//render text

		//render commands

		console_read_input(buffer, 12);
	}
}

void application_stop(Application* app)
{
	app->running = false;
}