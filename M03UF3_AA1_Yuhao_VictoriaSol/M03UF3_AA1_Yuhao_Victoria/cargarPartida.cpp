#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "tablero.h"
#include <vector>
#include "defines.h"

void cargarPartida(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir) {	//lector de archivos
	std::cout << "Escriu el nom de l'arxiu per carregar partida\n";
	std::string saveName;
	std::cin >> saveName;
	std::string line;
	char ficha;
	std::vector<std::string> tabRecopilado;
	if (saveName == "menu") {		//Si lo que ponemos de nombre es menu volvemos al menu principal
		menu(ganar, table, tableroVisual, repetir);
	}

	std::ifstream myfile;
	myfile.open(saveName+".tictacsave", std::ios::in);	//Abrimos el archivo para leer con el nombre que hemos puesto
	if (!myfile.is_open()) {							//Si no existe tal archivo nos mandan al menu principal
		std::cout << "No existeix tal arxiu\n";
		menu(ganar, table, tableroVisual, repetir);
	}
	if (myfile.is_open()) {			//Si esta abierto entonces, nos ponemos a leer linea por linea
		while (std::getline(myfile, line)) {
			std::cout << line << "\n";
			tabRecopilado.push_back(line);		//Pasamos linea a linea a un vector compuesto de strings
		}
		line = tabRecopilado[0];	//Pasamos el primer valor del vector a la string line

		for (int a = 0; a < COLUMNS; a++) {		//De la string cogemos cada valor, cada caracter y se lo pasamos a donde corresponde
			ficha = line[a];
			table[0][a] = ficha;
		}
		line = tabRecopilado[1];	//Recogemos el segundo valor del vector y hacemos lo mismo para el resto, como el tercero.
		for (int a = 0; a < COLUMNS; a++) {
			ficha = line[a];
			table[1][a] = ficha;
		}
		line = tabRecopilado[2];
		for (int a = 0; a < COLUMNS; a++) {
			ficha = line[a];
			table[2][a] = ficha;
		}
	}

	for (int b = 0; b < ROWS; b++) {	//Vaciamos el vector por razones de por si acaso.
		if (!tabRecopilado.empty()) {
			tabRecopilado.erase(tabRecopilado.begin());
		}
	}
	myfile.close();
	ganar = false;
	cargarTab(table, tableroVisual);	//Lo mandamos a poner esos valores en esta funcion, se lo pasamos al tablero visual

}