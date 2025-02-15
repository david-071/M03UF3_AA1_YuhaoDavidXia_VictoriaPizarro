#include <iostream>
#include <fstream>
#include <vector>
#include "savePartida.h"
#include "defines.h"

void escribirArchivo(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[TRECE][TRECE], bool& repetir, int& playerInputX, int& playerInputY, std::string &name) {
	bool escogeix = false;
	int eleccio;
	std::vector<std::string> tab;
	std::string nameArchivo = name + ".tictacsave";
	std::ofstream file(nameArchivo, std::ios::out | std::ios::trunc);

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
	//		nameArch();
	//	}
	//}		
	//file.close();
	//Guardar partida
	std::ofstream file1;
	file1.open(name + ".tictacsave", std::ios::out | std::ios::trunc);
	if (!file1.is_open()) {
		std::cout << "Error\n";
		return;
	}
	std::string line;
	for (int a = 0; a < 3; a++) {
		line = line +table[0][a];
	}

	tab.push_back(line);
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

	std::string line1;
	for (int a = 0; a < ROWS; a++) {
		file1 << tab[a];
		file1 << "\n";
	}
	file1.close();
	for (int a = 0; a < ROWS; a++) {
		if (!tab.empty()) {
			tab.erase(tab.begin());
		}
	}
	elegirAccion(ganar, table, tableroVisual, repetir, playerInputX, playerInputY);
}