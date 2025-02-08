#include <iostream>
#include <time.h>
#define ROWS 3
#define COLUMNS 3

void tablero(char table[COLUMNS][ROWS]) {

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void tableroInicio(char table[COLUMNS][ROWS]) {
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			table[i][j] = 'a';
		}
	}
}