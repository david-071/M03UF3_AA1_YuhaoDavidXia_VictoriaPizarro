#include <iostream>
#include "elegirCasilla.h"
#define ROWS 3
#define COLUMNS 3
void player(char table[ROWS][COLUMNS], int& playerInputX, int& playerInputY, bool& turn) {

		if (table[playerInputX][playerInputY] == 'a') {
			table[playerInputX][playerInputY] = 'X';
		}
		else{ playerInputs(table, playerInputX, playerInputY); }
	
}

void iaComprobar(char table[ROWS][COLUMNS], int& iaInputX, int& iaInputY, bool& turn) {
	if (table[iaInputX][iaInputY] == 'a') {
		table[iaInputX][iaInputY] = 'O';
	}
	else { playerInputs(table, iaInputX, iaInputY); }
}