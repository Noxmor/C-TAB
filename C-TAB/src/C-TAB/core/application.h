#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdbool.h>

typedef struct
{
	const char* title;
	bool running;
} Application;

Application* application_create(const char* title);
void application_run(Application* app);
void application_stop(Application* app);

#endif