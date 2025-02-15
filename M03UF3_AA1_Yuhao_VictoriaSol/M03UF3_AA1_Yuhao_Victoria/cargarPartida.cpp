#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "tablero.h"
#include <vector>
#include "defines.h"

void cargarPartida(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir) {
    std::cout << "Escriu el nom de l'arxiu per carregar partida\n";
    std::string saveName;
    std::cin >> saveName;

    if (saveName == "menu") { //Si lo que ponemos de nombre es menu volvemos al menu principal
        menu(ganar, table, tableroVisual, repetir);
        return;
    }

    std::ifstream myfile(saveName + ".tictacsave", std::ios::in); //Abrimos el archivo para leer con el nombre que hemos puesto
    if (!myfile.is_open()) { //Si no existe tal archivo nos mandan al menu principal
        std::cout << "No existeix tal arxiu\n";
        menu(ganar, table, tableroVisual, repetir);
        return;
    }

    std::string line;
    for (int i = 0; i < ROWS && std::getline(myfile, line); i++) {
        if (line.length() < COLUMNS) {  // Si la línea que obtenemos tiene menos columnas que las esperadas, consideramos que el archivo está corrupto o es de un formato incorrecto
            std::cout << "Error: Partida corrupta o formato incorrecto.\n";
            menu(ganar, table, tableroVisual, repetir);
            return;
        }
        // Copiamos cada caracter de la línea leída al tablero
        for (int j = 0; j < COLUMNS; j++) {
            table[i][j] = line[j];
        }
    }

    myfile.close();
    ganar = false;
    cargarTab(table, tableroVisual);
}