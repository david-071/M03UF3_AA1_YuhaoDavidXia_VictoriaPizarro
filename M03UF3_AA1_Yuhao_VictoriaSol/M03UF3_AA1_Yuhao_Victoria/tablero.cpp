#include <iostream>
#include "defines.h"
void tablero(char table[ROWS][COLUMNS], char tableroVisual[TRECE][TRECE]) {     //Creación del tablero visual con absolutamente nada
    for (int i = 0; i < COLUMNS; i++) {
        for (int j = 0; j < ROWS; j++) {
            table[i][j] = ' ';
        }
    }

    for (int i = 0; i < TRECE; i++) {
        for (int j = 0; j < TRECE; j++) {
            tableroVisual[i][j] = ' ';
        }
    }

    for (int a = 0; a < TRECE; a += 4) {
        for (int b = 0; b < TRECE; b++) {
            tableroVisual[a][b] = '-';
        }
    }

    for (int a = 2; a < 13; a += 4) {
        for (int b = 0; b < TRECE; b += 4) {
            tableroVisual[a][b] = '|';
        }
    }
}

void cargarTab(char table[ROWS][COLUMNS], char tableroVisual[TRECE][TRECE]) {       //Creacion del tablero visual pero sin cambiar los valores del otro tablero para que se quede lo que se guardó ahí
    for (int i = 0; i < TRECE; i++) {
        for (int j = 0; j < TRECE; j++) {
            tableroVisual[i][j] = ' ';
        }
    }


    for (int a = 0; a < TRECE; a += 4) {
        for (int b = 0; b < TRECE; b++) {
            tableroVisual[a][b] = '-';
        }
    }

    for (int a = 2; a < 13; a += 4) {
        for (int b = 0; b < TRECE; b += 4) {
            tableroVisual[a][b] = '|';
        }
    }
}