#include <iostream>
#include <vector>
#include <time.h>
#include "tablero.h"
#include "elegirCasilla.h"
#include "WinOrLose.h"

#define ROWS 3
#define COLUMNS 3

int main() {
	
	char table[COLUMNS][ROWS];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
	bool salir = false;


	while (!salir) {
		tablero(table);
		playerInputs(table, playerInputX, playerInputY);
		ia(table, iaInputX, iaInputY);

	}

	
	std::cout << "Termina";
}