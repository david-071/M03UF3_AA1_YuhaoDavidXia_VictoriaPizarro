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

void tablero(char table[ROWS][COLUMNS]) {
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			table[i][j] = 'a';
		}
	}
}

void tableroImprimir(char table[ROWS][COLUMNS]) {
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void winOrLose(char table[COLUMNS][ROWS], bool& ganar) {
    int num = 0;
    int winX = 0;
    bool ehe = false;
    while (!ehe) {
        for (int a = 0; a < 2; a++) {
            if (table[num][a] == 'X') {
                winX++;
            }
        }
        if (winX == 3) {
            std::cout << "Ganan las X\n";
            ganar = true;
        }

        winX = 0;
        for (int a = 0; a < 2; a++) {
            if (table[a][num] == 'X') {
                winX++;
            }
        }
        if (winX == 3) {
            std::cout << "Ganan las X\n";
            ganar = true;
        }

        if (num == 3) {
            ehe = true;
        }
        num++;
    }
    num = 0;
    winX = 0;
    ehe = false;
    while (!ehe) {
        for (int a = 0; a < 2; a++) {
            if (table[num][a] == 'O') {
                winX++;
            }
        }
        if (winX == 3) {
            ganar = true;
            std::cout << "Ganan las O\n";
        }

        winX = 0;
        for (int a = 0; a < 2; a++) {
            if (table[a][num] == 'O') {
                winX++;
            }
        }
        if (winX == 3) {
            ganar = true;
        }

        if (num == 3) {
            ehe = true;
        }
        num++;
    }
    num = 0;

    if (!ganar) {
        if (table[0][0] == 'X') {
            num++;
        }
        if (table[1][1] == 'X') {
            num++;
        }
        if (table[2][2] == 'X') {
            num++;
        }

        if (num >= 3) {
            std::cout << "Ganan las X\n";
            ganar = true;
        }
    }
    num = 0;
    if (!ganar) {
        if (table[0][2] == 'X') {
            num++;
        }
        if (table[1][1] == 'X') {
            num++;
        }
        if (table[2][0] == 'X') {
            num++;
        }

        if (num >= 3) {
            ganar = true;
            std::cout << "Ganan las X\n";
        }
    }
    num = 0;
    if (!ganar) {
        if (table[0][0] == 'O') {
            num++;
        }
        if (table[1][1] == 'O') {
            num++;
        }
        if (table[2][2] == 'O') {
            num++;
        }

        if (num >= 3) {
            ganar = true;
            std::cout << "Ganan las O\n";
        }
    }
    num = 0;
    if (!ganar) {
        if (table[0][2] == 'O') {
            num++;
        }
        if (table[1][1] == 'O') {
            num++;
        }
        if (table[2][0] == 'O') {
            num++;
        }

        if (num >= 3) {
            ganar = true;
            std::cout << "Ganan las O\n";
        }
    }
    num = 0;

    for (int a = 0; a < ROWS; a++) {
        for (int b = 0; b < COLUMNS; b++) {
            if (table[a][b] != 'a') {
                num++;
            }
        }
    }

    if (num == 9) {
        ganar = true;
        std::cout << "Ha habido un empate\n";
    }
}


int main() {
	
	char table[COLUMNS][ROWS];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
	int turn = 0;
    bool ganar = false;

	tablero(table);
	while (!ganar) {
        tableroImprimir(table);
		playerInputs(table, playerInputX, playerInputY);
		player(table, playerInputX, playerInputY, turn);
        winOrLose(table, ganar);
        std::cout << "\n\n";
        tableroImprimir(table);
		ia(table, iaInputX, iaInputY, turn);
        winOrLose(table, ganar);
        std::cout << "\n\n";
		
	}
	std::cout << "Termina";
}