#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "cargarPartida.h"
#include "menu.h"
#include "defines.h"
#include "playerInputs.h"
#include "savePartida.h"

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

void tableroImprimir(char table[ROWS][COLUMNS], char tableroVisual[TRECE][TRECE]) {
    tableroVisual[2][2] = table[0][0];
    tableroVisual[2][6] = table[0][1];
    tableroVisual[2][10] = table[0][2];

    tableroVisual[6][2] = table[1][0];
    tableroVisual[6][6] = table[1][1];
    tableroVisual[6][10] = table[1][2];

    tableroVisual[10][2] = table[2][0];
    tableroVisual[10][6] = table[2][1];
    tableroVisual[10][10] = table[2][2];
    
    for (int i = 0; i < TRECE; i++) {
        for (int j = 0; j < TRECE; j++) {
            std::cout << tableroVisual[i][j];
        }
        std::cout << std::endl;
    }

    
}
void winOrLose(char table[COLUMNS][ROWS], bool& ganar) {
    int num = 0;
    int winX = 0;
    bool comprobacion = false;
    while (!comprobacion) {
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
            comprobacion = true;
        }
        num++;
    }
    num = 0;
    winX = 0;
    comprobacion = false;
    while (!comprobacion) {
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
            comprobacion = true;
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

int main() {
	
	char table[COLUMNS][ROWS];
    char tableroVisual[TRECE][TRECE];
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
    bool ganar = false;
    bool salir = false;
    bool repetir = false;


    menu(ganar, table, tableroVisual, repetir);
    while (!repetir) {
        while (!ganar) {
            tableroImprimir(table, tableroVisual);
            elegirAccion(ganar, table, tableroVisual, repetir, playerInputX, playerInputY);
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