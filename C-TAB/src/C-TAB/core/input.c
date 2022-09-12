#include "input.h"

#include <conio.h>

bool input_key_pressed(int keycode)
{
	if (!kbhit())
		return false;

	return getch() == keycode;
}

bool input_any_key()
{
	return kbhit();
}

int input_get_pressed_key()
{
	if (!kbhit())
		return 0;

	return getch();
}