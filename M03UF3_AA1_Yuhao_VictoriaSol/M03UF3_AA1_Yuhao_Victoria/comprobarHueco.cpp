#include <iostream>
#include "elegirCasilla.h"
#include "comprobarHueco.h"
#define ROWS 3
#define COLUMNS 3
void player(char table[ROWS][COLUMNS], int& playerInputX, int& playerInputY)
{
	if (table[playerInputX][playerInputY] == 'a') {
		table[playerInputX][playerInputY] = 'X';
	}
	else {
		playerInputs(table, playerInputX, playerInputY);
	}
}

void iaComprobar(char table[ROWS][COLUMNS], int& iaInputX, int& iaInputY)
{
	if (table[iaInputX][iaInputY] == 'a') {
		table[iaInputX][iaInputY] = 'O';
	}
	else {
		ia(table, iaInputX, iaInputY);
	}
}
