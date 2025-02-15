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
void winOrLose(char table[COLUMNS][ROWS], bool& ganar) {    //Void de comprobar si hemos ganado o no
    int num = 0;
    int winX = 0;
    bool comprobacion = false;

    //Comprobación de win de las X
    while (!comprobacion) {                 //Mientras no se acabe de comprobar todo, no se acabará este while
        winX = 0;
        for (int a = 0; a < 3; a++) {       //Comprobamos verticalmente la primera columna, si en esa columna encuentra 3 X entonces winX será 3
            if (table[num][a] == 'X') {     
                winX++;
            }
        }
        if (winX == 3) {                    //Si winX es 3, es que hay 3 x en esa columna y ganaremos
            std::cout << "Ganan las X\n";
            ganar = true;
            comprobacion = true;            //Comprueba la siguiente fila y se acaba
        }
        winX = 0;                           //Reiniciamos el contador de encontrar Xs
        for (int a = 0; a < 3; a++) {       //Comprobamos horizontalmente
            if (table[a][num] == 'X') {
                winX++;
            }
        }
        if (winX == 3) {
            std::cout << "Ganan las X\n";
            ganar = true;
            comprobacion = true;
        }

        if (num == 3) {                 //Si esto llega a 3, significa que hemos comprobado todas las columnas y se acaba el bucle
            comprobacion = true;
        }
        num++;                          //Esto es para comprobar el resto de columnas o filas del tablero
    }
    num = 0;
    winX = 0;
    comprobacion = false;

    //Comprobacion de las O, lo mismo que las X pero con las O
    while (!comprobacion) {
        winX = 0;
        for (int a = 0; a < 3; a++) {
            if (table[num][a] == 'O') {
                winX++;
            }
        }
        if (winX == 3) {
            ganar = true;
            comprobacion = true;
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
            comprobacion = true;
            ganar = true;
        }

        if (num == 3) {
            comprobacion = true;
        }
        num++;
    }
    num = 0;

    if (!ganar) {                   //Si en una de las 2 anteriores comprobaciones hay una win horizontal o vertical, entonces esto no se ejecuta
        if (table[0][0] == 'X') {   //Si encontramos la diagonal de izquierda arriba a derecha abajo ganan las X
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
    if (!ganar) {               //Comprobamos la otra diagonal
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
    num = 0;        //Comprobamos diagonales de los O
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

    for (int a = 0; a < ROWS; a++) {    //Comprobamos como de lleno está el tablero, si está lleno num será 9
        for (int b = 0; b < COLUMNS; b++) {
            if (table[a][b] != ' ') {
                num++;
            }
        }
    }

    if (!ganar) {
        if (num == 9) {     //Si en las otras comprobaciones no hay wins y esto llega a 9, entonces tenemos un empate
            ganar = true;
            std::cout << "Ha habido un empate\n";
        }
    }
}

int main() {
	
	char table[COLUMNS][ROWS];  //El tablero para cargar partidas, guardar partidas
    char tableroVisual[TRECE][TRECE];   //El tablero que vemos en pantalla
	int playerInputX, playerInputY;
	int iaInputX, iaInputY;
    bool ganar = false;
    bool salir = false;
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
}