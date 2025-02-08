#include <iostream>
#include "comprobarHueco.h"
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
	player(table, playerInputX, playerInputY);
}


void ia(char table[ROWS][COLUMNS], int& iaInputX, int& iaInputY) {

	srand(time(NULL));
	iaInputX = rand() % 3;
	iaInputY = rand() % 3;
	iaComprobar(table, iaInputX, iaInputY);

}