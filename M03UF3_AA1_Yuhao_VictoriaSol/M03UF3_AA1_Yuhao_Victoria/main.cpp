#include <iostream>
#include <vector>
#include "constants.h"

int main() {
	
	char table[ROWS][COLUMNS];
	char inputX;
	char inputY;
	bool otro = true;

	std::cout << "Pon un numero\n";
	std::cin >> inputX;

	if (inputX == '0' || inputX == '1' || inputX == '2') {
		otro = true;
	}
	else {
		otro = false;
	}
	while (!otro) {
		std::cout << "Pon un FUCKING numero mamon" << "\n";
		std::cin >> inputX;
		if (inputX == '0' || inputX == '1' || inputX == '2') {
			otro = true;
		}
		else {
			otro = false;
		}
	}
	std::cin >> inputY;
	if (inputX == '0' || inputX == '1' || inputX == '2') {
		otro = true;
	}
	else {
		otro = false;
	}
	while (!otro) {
		std::cout << "Pon un FUCKING numero mamon" << "\n";
		std::cin >> inputY;
		if (inputY == 0 || inputY == 1 || inputY == 2) {
			otro = true;
		}
		else {
			otro = false;
		}
	}

}