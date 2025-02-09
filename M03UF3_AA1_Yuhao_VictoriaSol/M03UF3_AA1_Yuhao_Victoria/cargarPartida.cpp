#include <iostream>
#include <fstream>

void cargarPartida() {
	std::cout << "Escriu el nom de l'arxiu per carregar partida\n";
	std::string saveName;

	std::ifstream myfile;
	myfile.open(saveName+".tictacasave", std::ios::in);
	if (!myfile.is_open()) {
		std::cout << "No existeix tal arxiu, tornant al menú...\n";
		
	}
}