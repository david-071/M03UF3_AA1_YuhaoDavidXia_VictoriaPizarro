#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "cargarPartida.h"
#include "menu.h"
#include "defines.h"
#include "playerInputs.h"
#include "savePartida.h"

void player(char table[ROWS][COLUMNS], int &playerInputX, int &playerInputY) {  //Colocación de la posición elegida por el player

	while (table[playerInputX][playerInputY] != ' ') {  //Si no esta vacio lo escogido lo mandamos a volver a elegir
		std::cout << "Ya hay una pieza en la posicion elegida" << std::endl;
		playerInputs(table, playerInputX, playerInputY);
	}

	table[playerInputX][playerInputY] = 'X';    //Colocamos la X

}

void ia(char table[ROWS][COLUMNS], int &iaInputX, int &iaInputY) {

	srand(time(NULL));  //Randomizer

	iaInputX = rand() % 3;  //La ia elige una posición random entre el 0 y el 2 para tanto las x como las y
	iaInputY = rand() % 3;

	while (table[iaInputX][iaInputY] != ' ') {      //Hasta que no encuentre una posición vacía seguirá generando numeros randoms
		iaInputX = rand() % 3;
		iaInputY = rand() % 3;
	}

	table[iaInputX][iaInputY] = 'O';        //Colocamos la ficha de la ia
}

void tableroImprimir(char table[ROWS][COLUMNS], char tableroVisual[TRECE][TRECE]) {
    tableroVisual[2][2] = table[0][0];      //Pasamos al tablero que se ve las piezas que hemos puesto en el otro tablero
    tableroVisual[2][6] = table[0][1];      //Si hay una pieza X en 0,0 entonces en el tablero visual se pondrá esa pieza en 2,2 y así cada pieza en su sitio
    tableroVisual[2][10] = table[0][2];

    tableroVisual[6][2] = table[1][0];
    tableroVisual[6][6] = table[1][1];
    tableroVisual[6][10] = table[1][2];

    tableroVisual[10][2] = table[2][0];
    tableroVisual[10][6] = table[2][1];
    tableroVisual[10][10] = table[2][2];
    
    for (int i = 0; i < TRECE; i++) {   //Imprimimos el tablero
        for (int j = 0; j < TRECE; j++) {
            std::cout << tableroVisual[i][j];
        }
        std::cout << std::endl;
    }

    
}

bool checkWin(char table[ROWS][COLUMNS], char piece) {
    for (int i = 0; i < 3; i++) {
        if ((table[i][0] == piece && table[i][1] == piece && table[i][2] == piece) || // Mira si hemos ganado mediante filas
            (table[0][i] == piece && table[1][i] == piece && table[2][i] == piece)) { // Mira si hemos ganado mediante columnas
            return true;
        }
    }
    if ((table[0][0] == piece && table[1][1] == piece && table[2][2] == piece) ||  // Mira si hemos ganado mendiante diagonal 
        (table[0][2] == piece && table[1][1] == piece && table[2][0] == piece)) {  // Mira si hemos ganado mendiante diagonal inversa
        return true;
    }
    return false;
}

void winOrLose(char table[ROWS][COLUMNS], bool& ganar) {
    if (checkWin(table, 'X')) {
        std::cout << "Ganan las X\n";
        ganar = true;
    }
    else if (checkWin(table, 'O')) {
        std::cout << "Ganan las O\n";
        ganar = true;
    }
    else {
        bool empate = true;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (table[i][j] == ' ') {
                    empate = false;
                    break;
                }
            }
        }
        if (empate) {
            std::cout << "Ha habido un empate\n";
            ganar = true;
        }
    }
}

int main() {
	
	char table[COLUMNS][ROWS];  //El tablero para cargar partidas, guardar partidas
    char tableroVisual[TRECE][TRECE];   //El tablero que vemos en pantalla
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
    bool ganar = false;
    bool repetir = false;


    menu(ganar, table, tableroVisual, repetir); //Lo mandamos al menú principal
    while (!repetir) {                          //Se repite este bucle infinitamente hasta que salgamos desdel menu
        while (!ganar) {                        //Se repite este bucle hasta que se gane o se empate
            tableroImprimir(table, tableroVisual);
            elegirAccion(ganar, table, tableroVisual, repetir, playerInputX, playerInputY); //Lo mandamos al menú de elegir de si guardar partida, poner una ficha o ir al menu principal
            if(!repetir)player(table, playerInputX, playerInputY);      //Si repetir esta en true entonces es que no hemos seleccionado una ficha y eso genera error
            winOrLose(table, ganar);    //Comprobar si gana o no
            std::cout << "\n\n";
            tableroImprimir(table, tableroVisual);  //Imprimimos el tablero
            if (!ganar) {                           //Si el player gana entonces no es necesario que se hagan estas funciones y luego generaria un bucle infinito de intentar poner una ficha la ia
                ia(table, iaInputX, iaInputY);
                winOrLose(table, ganar);
                std::cout << "\n\n";
            }
        }
        if(!repetir)menu(ganar, table, tableroVisual, repetir);     //Esto es porque si en el otro menu nos vamos de vuelta al menu y si le damos a salir, podamos salir.
    }

    std::cout << "Termina";
    return 0;
}