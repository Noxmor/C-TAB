#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

bool input_key_pressed(int keycode);
bool input_any_key();
int input_get_pressed_key();

#endif