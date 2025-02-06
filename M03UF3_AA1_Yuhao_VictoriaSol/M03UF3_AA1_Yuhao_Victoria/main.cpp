#include <iostream>
#include <vector>

#define ROWS 3
#define COLUMNS 3

int main() {
	
	char table[COLUMNS][ROWS];
	int playerInputX, playerInputY;

	std::cout << "Ingrese una posicion valida (0-2): " << std::endl;
	std::cin >> playerInputX >> playerInputY;

	while (playerInputX < 0 || playerInputX > 2) {

		std::cout << "Posicion X invalido. Ingrese un numero entre el 0 y el 2" << std::endl;
		std::cin >> playerInputX;

	}

	while (playerInputY < 0 || playerInputY > 2) {

		std::cout << "Posicion Y invalido. Ingrese un numero entre el 0 y el 2" << std::endl;
		std::cin >> playerInputY;

	}
}