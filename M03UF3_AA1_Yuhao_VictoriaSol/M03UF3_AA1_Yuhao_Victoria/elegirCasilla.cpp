#include <iostream>
#define ROWS 3
#define COLUMNS 3

void player(char table[ROWS][COLUMNS], int& playerInputX, int& playerInputY, int& turn) {

	while (table[playerInputX][playerInputY] != 'a') {
		std::cout << "Ya hay una pieza en la posicion elegida" << std::endl;
		playerInputs(table, playerInputX, playerInputY);
	}

	table[playerInputX][playerInputY] = 'X';
	turn++;

}

int ia(char table[ROWS][COLUMNS], int& iaInputX, int& iaInputY, int& turn) {

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