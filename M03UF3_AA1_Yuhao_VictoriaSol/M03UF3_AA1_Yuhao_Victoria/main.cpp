#include <iostream>
#include <vector>
#include <time.h>
#include "tablero.h"
#include "elegirCasilla.h"
#include "WinOrLose.h"
#include <windows.h>

#define ROWS 3
#define COLUMNS 3

int main() {
	
	char table[COLUMNS][ROWS];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
	bool salir = false;
	bool ganar = false;
		
		tableroInicio(table);
		while (!ganar) {
			tablero(table);
			playerInputs(table, playerInputX, playerInputY);
			winOrLose(table, ganar);
			tablero(table);
			ia(table, iaInputX, iaInputY);
			winOrLose(table, ganar);
			system("cls");
		}
	
	std::cout << "Termina";
}