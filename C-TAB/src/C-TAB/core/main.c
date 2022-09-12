#include "C-TAB/core/application.h"

#include <stdlib.h>

int main(int argc, char** argv)
{
	Application* app = application_create("C-TAB");
	application_run(app);
	free(app);

	return 0;
}