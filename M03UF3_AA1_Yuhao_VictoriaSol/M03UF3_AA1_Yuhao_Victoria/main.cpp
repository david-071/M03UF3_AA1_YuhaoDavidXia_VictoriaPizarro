#include <iostream>
#include <vector>
#include <time.h>
#include "tablero.h"
#include "elegirCasilla.h"

#define ROWS 3
#define COLUMNS 3

void playerInputs(char table[ROWS][COLUMNS], int& playerInputX, int& playerInputY) {

	std::cout << "Ingrese una posicion valida (0-2): " << std::endl;
	std::cin >> playerInputX >> playerInputY;

	while ((playerInputX < 0 || playerInputX > 2)) {

		std::cout << "Posicion X invalido. Ingrese un numero entre el 0 y el 2" << std::endl;
		std::cin >> playerInputX;

	}

	while ((playerInputY < 0 || playerInputY > 2)) {

		std::cout << "Posicion Y invalido. Ingrese un numero entre el 0 y el 2" << std::endl;
		std::cin >> playerInputY;

	}
}


int main() {
	
	char table[COLUMNS][ROWS];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
	int turn = 0;


	while (turn < 9) {

		tablero(table);

		playerInputs(table, playerInputX, playerInputY);
		player(table, playerInputX, playerInputY, turn);
		ia(table, iaInputX, iaInputY, turn);

		for (int i = 0; i < COLUMNS; i++) {
			for (int j = 0; j < ROWS; j++) {
				std::cout << table[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << "Termina";
}