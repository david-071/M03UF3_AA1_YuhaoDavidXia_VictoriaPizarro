#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "cargarPartida.h"
#include "menu.h"


#define ROWS 3
#define COLUMNS 3
#define WHAT 13

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

void player(char table[ROWS][COLUMNS], int &playerInputX, int &playerInputY) {

	while (table[playerInputX][playerInputY] != ' ') {
		std::cout << "Ya hay una pieza en la posicion elegida" << std::endl;
		playerInputs(table, playerInputX, playerInputY);
	}

	table[playerInputX][playerInputY] = 'X';

}

void ia(char table[ROWS][COLUMNS], int &iaInputX, int &iaInputY) {

	srand(time(NULL));

	iaInputX = rand() % 3;
	iaInputY = rand() % 3;

	while (table[iaInputX][iaInputY] != ' ') {
		iaInputX = rand() % 3;
		iaInputY = rand() % 3;
	}

	table[iaInputX][iaInputY] = 'O';
}


void tableroImprimir(char table[ROWS][COLUMNS], char tableroVisual[WHAT][WHAT]) {
    tableroVisual[2][2] = table[0][0];
    tableroVisual[2][6] = table[0][1];
    tableroVisual[2][10] = table[0][2];

    tableroVisual[6][2] = table[1][0];
    tableroVisual[6][6] = table[1][1];
    tableroVisual[6][10] = table[1][2];

    tableroVisual[10][2] = table[2][0];
    tableroVisual[10][6] = table[2][1];
    tableroVisual[10][10] = table[2][2];
    
    for (int i = 0; i < WHAT; i++) {
        for (int j = 0; j < WHAT; j++) {
            std::cout << tableroVisual[i][j];
        }
        std::cout << std::endl;
    }

    
}
void winOrLose(char table[COLUMNS][ROWS], bool& ganar) {
    int num = 0;
    int winX = 0;
    bool ehe = false;
    while (!ehe) {
        winX = 0;
        for (int a = 0; a < 3; a++) {
            if (table[num][a] == 'X') {
                winX++;
            }
        }
        if (winX == 3) {
            std::cout << "Ganan las X\n";
            ganar = true;
        }
        winX = 0;
        for (int a = 0; a < 3; a++) {
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
        winX = 0;
        for (int a = 0; a < 3; a++) {
            if (table[num][a] == 'O') {
                winX++;
            }
        }
        if (winX == 3) {
            ganar = true;
            std::cout << "Ganan las O\n";
        }

        winX = 0;
        for (int a = 0; a < 3; a++) {
            if (table[a][num] == 'O') {
                winX++;
            }
        }
        if (winX == 3) {
            std::cout << "Ganan las O\n";
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

        if (num == 3) {
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

        if (num == 3) {
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

        if (num == 3) {
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

        if (num == 3) {
            ganar = true;
            std::cout << "Ganan las O\n";
        }
    }
    num = 0;

    for (int a = 0; a < ROWS; a++) {
        for (int b = 0; b < COLUMNS; b++) {
            if (table[a][b] != ' ') {
                num++;
            }
        }
    }

    if (!ganar) {
        if (num == 9) {
            ganar = true;
            std::cout << "Ha habido un empate\n";
        }
    }
}

void savePartida() {
    int eleccion = -1;
    std::cout << "Jugador, qu� vols fer?\n"
        << "Posar una fitxa (0)\n"
        << "Guardar partida (1)\n"
        << "Tornar al men� principal (2)\n";
    while (eleccion < 0 || eleccion > 2) {
        std::cin >> eleccion;
    }
}


int main() {
	
	char table[COLUMNS][ROWS];
    char tableroVisual[WHAT][WHAT];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
    bool ganar = false;
    bool salir = false;
    bool repetir = false;


    menu(ganar, table, tableroVisual, repetir);
    while (!repetir) {
        while (!ganar) {
            tableroImprimir(table, tableroVisual);
            playerInputs(table, playerInputX, playerInputY);
            player(table, playerInputX, playerInputY);
            winOrLose(table, ganar);
            std::cout << "\n\n";
            tableroImprimir(table, tableroVisual);
            if (!ganar) {
                ia(table, iaInputX, iaInputY);
                winOrLose(table, ganar);
                std::cout << "\n\n";
            }
        }
        menu(ganar, table, tableroVisual, repetir);
    }
        std::cout << "Termina";
}