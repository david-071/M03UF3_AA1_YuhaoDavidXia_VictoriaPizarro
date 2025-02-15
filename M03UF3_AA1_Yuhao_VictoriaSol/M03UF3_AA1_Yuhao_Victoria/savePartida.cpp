#include <iostream>
#include <fstream>
#include "defines.h"
#include "menu.h"
#include "playerInputs.h"
#include "siName.h"
void nameArch(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir, int& playerInputX, int& playerInputY) {
    std::string name;
    std::string menuu = "menu";
    bool si = false;
    std::cout << "No pongas de name: menu, gracias\n";
    while (!si) {
        std::cin >> name;

        if (name == menuu) {
            si = false;
        }
        else {
            si = true;
        }
    }
    escribirArchivo(ganar, table, tableroVisual, repetir, playerInputX, playerInputY, name);

}

void elegirAccion(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir, int& playerInputX, int& playerInputY) {
    int eleccion = -1;
    std::cout << "Jugador, que vols fer?\n"
        << "Posar una fitxa (0)\n"
        << "Guardar partida (1)\n"
        << "Tornar al menu principal (2)\n";
    while (eleccion < 0 || eleccion > 2) {
        std::cin >> eleccion;
    }

    switch (eleccion) {
    case 0:
        playerInputs(table, playerInputX, playerInputY);
        break;
    case 1:
        nameArch(ganar, table, tableroVisual, repetir, playerInputX, playerInputY);
        break;
    case 2:
        std::cout << "Tornant al menu principal\n";
        menu(ganar, table, tableroVisual, repetir);

        break;
    default:
        break;
    }
}