#include <iostream>
#include "cargarPartida.h"
#include "tablero.h"
#include "defines.h"

//Este es el menu principal
void menu(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir) {
    int eleccion = -1;  //Esto es para que se meta en el while siguiente
    std::cout << " ---------- Tres en ratlla ----------\n\n";
    std::cout << "    1 - Nova partida\n"
        << "    2 - Carregar partida guardada\n"
        << "    3 - Sortir\n\n" << "Tria una opcio:\n";
    while (eleccion < 1 || eleccion > 3) {      //Solo podemos elegir un número del 1 al 3
        std::cin >> eleccion;
    }

    switch (eleccion) {
    case 1:                     //Si elegimos 1 crearemos un tablero nuevo, nos manda a la función tablero que nos pone un tablero sin nada
        ganar = false;
        tablero(table, tableroVisual);
        break;
    case 2:
        std::cout << "Carregant partida?\n";    //El 2 es para cargar una partida guardada
        cargarPartida(ganar, table, tableroVisual, repetir);
        break;
    case 3:                     //Hace que no nos podamos meter en el bucle de !ganar y no se repita el de repetir
        repetir = true;
        ganar = true;
        break;
    default:
        break;
    }
}
