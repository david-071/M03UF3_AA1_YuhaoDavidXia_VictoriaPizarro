#include <iostream>
#define ROWS 3
#define COLUMNS 3
#define WHAT 13

void tablero(char table[ROWS][COLUMNS], char tableroVisual[WHAT][WHAT]) {
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            table[i][j] = ' ';
        }
    }

    for (int i = 0; i < WHAT; i++) {
        for (int j = 0; j < WHAT; j++) {
            tableroVisual[i][j] = ' ';
        }
    }

    for (int a = 0; a < WHAT; a += 4) {
        for (int b = 0; b < WHAT; b++) {
            tableroVisual[a][b] = '-';
        }
    }

    for (int a = 2; a < 13; a += 4) {
        for (int b = 0; b < WHAT; b += 4) {
            tableroVisual[a][b] = '|';
        }
    }
}

void cargarTab(char table[ROWS][COLUMNS], char tableroVisual[WHAT][WHAT]) {
    for (int i = 0; i < WHAT; i++) {
        for (int j = 0; j < WHAT; j++) {
            tableroVisual[i][j] = ' ';
        }
    }


    for (int a = 0; a < WHAT; a += 4) {
        for (int b = 0; b < WHAT; b++) {
            tableroVisual[a][b] = '-';
        }
    }

    for (int a = 2; a < 13; a += 4) {
        for (int b = 0; b < WHAT; b += 4) {
            tableroVisual[a][b] = '|';
        }
    }
}