#include <iostream>
#include <vector>
#include <time.h>

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

void player(char table[ROWS][COLUMNS], int &playerInputX, int &playerInputY, int &turn) {

	while (table[playerInputX][playerInputY] != 'a') {
		std::cout << "Ya hay una pieza en la posicion elegida" << std::endl;
		playerInputs(table, playerInputX, playerInputY);
	}

	table[playerInputX][playerInputY] = 'X';
	turn++;

}

int ia(char table[ROWS][COLUMNS], int &iaInputX, int &iaInputY, int &turn) {

	if (turn == 9) {
		return 0;
	}

	srand(time(NULL));

	iaInputX = rand() % 3;
	iaInputY = rand() % 3;

	while (table[iaInputX][iaInputY] != 'a') {
		iaInputX = rand() % 3;
		iaInputY = rand() % 3;
	}

	table[iaInputX][iaInputY] = 'O';
	turn++;
}

int main() {
	
	char table[COLUMNS][ROWS];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
	int turn = 0;

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			table[i][j] = 'a';
		}
	}

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}

	while (turn < 9) {

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