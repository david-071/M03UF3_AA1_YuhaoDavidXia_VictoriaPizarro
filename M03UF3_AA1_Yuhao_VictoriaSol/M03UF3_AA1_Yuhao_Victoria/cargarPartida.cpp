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
	std::string line;
	char ficha;
	std::vector<std::string> tabRecopilado;
	if (saveName == "menu") {
		menu(ganar, table, tableroVisual, repetir);
	}

	std::ifstream myfile;
	myfile.open(saveName+".tictacsave", std::ios::in);
	if (!myfile.is_open()) {
		std::cout << "No existeix tal arxiu\n";
		menu(ganar, table, tableroVisual, repetir);
	}
	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			std::cout << line << "\n";
			tabRecopilado.push_back(line);
		}
		line = tabRecopilado[0];

		for (int a = 0; a < COLUMNS; a++) {
			ficha = line[a];
			table[0][a] = ficha;
		}
		line = tabRecopilado[1];
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

	for (int b = 0; b < ROWS; b++) {
		if (!tabRecopilado.empty()) {
			tabRecopilado.erase(tabRecopilado.begin());
		}
	}
	myfile.close();
	ganar = false;
	cargarTab(table, tableroVisual);

}