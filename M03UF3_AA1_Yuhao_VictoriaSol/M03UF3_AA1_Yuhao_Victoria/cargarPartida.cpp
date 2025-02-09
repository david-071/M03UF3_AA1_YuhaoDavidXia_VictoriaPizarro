#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"
#include "tablero.h"
#include <vector>
#define ROWS 3
#define COLUMNS 3
#define WHAT 13

void cargarPartida(bool& ganar, char table[COLUMNS][ROWS], char tableroVisual[WHAT][WHAT], bool& repetir) {
	std::cout << "Escriu el nom de l'arxiu per carregar partida\n";
	std::string saveName;
	std::cin >> saveName;
	std::string line;
	char wha;
	std::vector<std::string> yeah;
	if (saveName == "menu") {
		menu(ganar, table, tableroVisual, repetir);
	}

	std::ifstream myfile;
	myfile.open(saveName+".txt", std::ios::in);
	if (!myfile.is_open()) {
		std::cout << "No existeix tal arxiu\n";
		menu(ganar, table, tableroVisual, repetir);
	}
	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			std::cout << line << "\n";
			yeah.push_back(line);
		}
		line = yeah[0];
		wha = line[0];
		std::cout << wha << "\n";
		table[0][0] = wha;
		wha = line[1];
		table[0][1] = wha;
		wha = line[2];
		table[0][2] = wha;

		line = yeah[1];
		wha = line[0];
		table[1][0] = wha;
		wha = line[1];
		table[1][1] = wha;
		wha = line[2];
		table[1][2] = wha;

		line = yeah[2];
		wha = line[0];
		table[2][0] = wha;
		wha = line[1];
		table[2][1] = wha;
		wha = line[2];
		table[2][2] = wha;
	}

	for (int b = 0; b < ROWS; b++) {
		if (yeah.empty()) {
			yeah.erase(yeah.begin());
		}
	}
	
	myfile.close();
	cargarTab(table, tableroVisual);

}