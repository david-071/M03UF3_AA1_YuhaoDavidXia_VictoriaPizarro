#include <iostream>
#include <time.h>
#define ROWS 3
#define COLUMNS 3

void winOrLose(char table[COLUMNS][ROWS], bool &ganar) {
    int num = 0;
    int winX = 0;
    bool ehe = false;
    while (!ehe) {
            for (int a = 0; a < 2; a++) {
                if (table[num][a] == 'X') {
                    winX++;
                }
            }
            if (winX == 3) {
                std::cout << "Ganan las X\n";
                ganar = true;
            }
        
        winX = 0;
            for (int a = 0; a < 2; a++) {
                if (table[a][num] == 'X') {
                    winX++;
                }
            }
            if (winX == 3) {
                std::cout << "Ganan las X\n";
                ganar = true;
            }
        
        if (num == 3) {
            ehe = true;
        }
        num++;
    }
    num = 0;
    winX = 0;
    ehe = false;
    while (!ehe) {
            for (int a = 0; a < 2; a++) {
                if (table[num][a] == 'O') {
                    winX++;
                }
            }
            if (winX == 3) {
                ganar = true;
                std::cout << "Ganan las O\n";
            }
        
        winX = 0;
        for (int a = 0; a < 2; a++) {
            if (table[a][num] == 'O') {
                winX++;
            }
            }
            if (winX == 3) {
                ganar = true;
            }
        
        if (num == 3) {
            ehe = true;
        }
        num++;
    }
    num = 0;

    if (!ganar) {
        if (table[0][0] == 'X') {
            num++;
        }
        if (table[1][1] == 'X') {
            num++;
        }
        if (table[2][2] == 'X') {
            num++;
        }

        if (num >= 3) {
            ganar = true;
        }
    }
    num = 0;
    if (!ganar) {
        if (table[0][2] == 'X') {
            num++;
        }
        if (table[1][1] == 'X') {
            num++;
        }
        if (table[2][0] == 'X') {
            num++;
        }

        if (num >= 3) {
            ganar = true;
        }
    }
    num = 0;
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

        if (num >= 3) {
            ganar = true;
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

        if (num >= 3) {
            ganar = true;
        }
    }
    num = 0;

    for (int a = 0; a < ROWS; a++) {
        for (int b = 0; b < COLUMNS; b++) {
            if (table[a][b] != 'a') {
                num++;
            }
        }
    }

    if (num == 9) {
        ganar = true;
        std::cout << "Ha habido un empate\n";
    }
}