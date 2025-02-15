#include<iostream>
#include "defines.h"

//Aqui ponemos donde quiere poner su pieza el jugador, donde solo podemos del 0 al 2, si ponemos 3 no nos dejará salir del bucle
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