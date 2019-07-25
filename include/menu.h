/*
menu.h

Aron Lebani
6 March 2016
*/

#ifndef MENU_H

#define MENU_H

#include "math.h"
#include "alien.h"

void menu(math& game);
// Runs the menu

int selectItem(alien& name);
// Scrolls through menu
// Returns selected item

#endif