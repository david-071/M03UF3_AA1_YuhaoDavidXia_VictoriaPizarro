#include <iostream>
#include "cargarPartida.h"
#include "tablero.h"
#define ROWS 3
#define COLUMNS 3
#define WHAT 13


void menu(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[WHAT][WHAT], bool& repetir) {
    int eleccion = -1;
    std::cout << " ---------- Tres en ratlla ----------\n\n";
    std::cout << "    1 - Nova partida\n"
        << "    2 - Carregar partida guardada\n"
        << "    3 - Sortir\n\n" << "Tria una opcio:\n";
    while (eleccion < 1 || eleccion > 3) {
        std::cin >> eleccion;
    }

    switch (eleccion) {
    case 1:
        ganar = false;
        tablero(table, tableroVisual);
        break;
    case 2:
        std::cout << "Carregant partida?\n";
        cargarPartida(ganar, table, tableroVisual, repetir);
        break;
    case 3:
        repetir = true;
        ganar = true;
        break;
    default:
        break;
    }
}
