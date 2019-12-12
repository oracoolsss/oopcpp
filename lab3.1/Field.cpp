//
// Created by oracool on 10.12.2019.
//

#include <cstdio>
#include "Field.h"

Field::Field() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if((i + j) % 2 == 0) {
                fieldSquares[i][j] = (unsigned char)178;
            }
            else {
                fieldSquares[i][j] = (unsigned char)176;
            }
        }
    }

    this->fillWithPieces();
}

void Field::setSquare(std::pair<int, int> cords, std::string newValue) {
    fieldSquares[cords.first][cords.second] = newValue;
}

void Field::printField() {
    for (int i = 0; i < 8; ++i) {
        printf("%d", 8 - i);
        for (int j = 0; j < 8; ++j) {
            std::cout << fieldSquares[i][j];
        }
        printf("\n");
    }
    std::cout << " ";
    for (int k = 1; k <= 8; ++k) {
        printf("%c ", 64 + k);
    }
    std::cout << std::endl;
}

void Field::setStandartSquare(std::pair<int, int> cords) {
    if((cords.first + cords.second) % 2 == 0) {
        fieldSquares[cords.first][cords.second] = (unsigned char)178;
    }
    else {
        fieldSquares[cords.first][cords.second] = (unsigned char)176;
    }
}

void Field::fillWithPieces() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            if((i + j) % 2 != 0) {
                fieldSquares[i][j] = "P ";
            }
            if((14 - i - j) % 2 != 0) {
                fieldSquares[7 - i][7 - j] = "O ";
            }
        }
    }
}

