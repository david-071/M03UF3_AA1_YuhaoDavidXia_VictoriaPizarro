#include <iostream>
#include <fstream>
#include <vector>
#include "savePartida.h"
#include "defines.h"


//Y esta es la función de guardar partida
void escribirArchivo(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir, int& playerInputX, int& playerInputY, std::string &name) {
	bool escogeix = false;
	int eleccio;
	std::vector<std::string> tab;
	//std::string nameArchivo = name + ".tictacsave";
	//std::ofstream file(nameArchivo, std::ios::out);

	//if (file.fail()) {
	//	std::cout << "Aquest arxiu ja existeix, vols reemplaçar-ho o vols canviar el name?\n";
	//	std::cout << "0, per canviar el nom\n1, per reemplaçar l'arxiu\n";

	//	while (!escogeix) {
	//		std::cin >> eleccio;
	//		if (eleccio < 0 || eleccio > 1) {
	//			escogeix = false;
	//		}
	//		else {
	//			escogeix = true;
	//		}
	//	}
	//	if (eleccio == 0) {
	//		nameArch(ganar, table, tableroVisual, repetir, playerInputX, playerInputY);
	//	}
	//}		
	//file.close();
	//Guardar partida
	std::ofstream file1;	//Abrimos un archivo con el nombre que nos haya indicado el jugador
	file1.open(name + ".tictacsave", std::ios::out | std::ios::trunc);
	if (!file1.is_open()) {		//Si no se puede tenemos error
		std::cout << "Error\n";
		return;
	}
	std::string line;	//Creamos una string
	for (int a = 0; a < 3; a++) {	//Le ponemos de valor esa string los valores de la primera fila, como? concatenando
		line = line +table[0][a];
	}

	tab.push_back(line);	//Lo añadimos a un vector y hacemos lo mismo con las otras 2 filas
	std::string line2;
	for (int a = 0; a < 3; a++) {
		line2 = line2 + table[1][a];
	}

	tab.push_back(line2);
	std::string line3;
	for (int a = 0; a < 3; a++) {
		line3 = line3 + table[2][a];
	}
	tab.push_back(line3);

	std::string line1;					//Le escribimos al archivo, el primer valor del vector, el segundo y el tercero, con un salto de linea de por medio
	for (int a = 0; a < ROWS; a++) {
		file1 << tab[a];
		file1 << "\n";
	}
	file1.close();
	for (int a = 0; a < ROWS; a++) {		//Vaciamos el vector
		if (!tab.empty()) {
			tab.erase(tab.begin());
		}
	}
	elegirAccion(ganar, table, tableroVisual, repetir, playerInputX, playerInputY);	//Lo enviamos al menu del player (el principal no)
}