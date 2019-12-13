//
// Created by oracool on 11.12.2019.
//

#include "GameMechanics.h"
using namespace std;
bool std::isSquareEmpty(Field *field, pair<int, int> cords) {
    unsigned char square1 = 178;
    unsigned char square2 = 176;

    return (unsigned char)field->fieldSquares[cords.first][cords.second][0] == square1
    || (unsigned char)field->fieldSquares[cords.first][cords.second][0] == square2;
}

bool std::isPieceOnSquare(Field *field, pair<int, int> cords, Color color) {
    if(color == WHITE) {
        if(field->fieldSquares[cords.first][cords.second][0] == 'O' || field->fieldSquares[cords.first][cords.second][0] == 'Q') {
            return true;
        }
    }
    if(color == BLACK) {
        if(field->fieldSquares[cords.first][cords.second][0] == 'P' || field->fieldSquares[cords.first][cords.second][0] == 'R') {
            return true;
        }
    }
    return false;
}

bool std::isPossibleToMove(Field *field, pair<int, int> startCords, pair<int, int> finishCords) {
    if(field->fieldSquares[startCords.first][startCords.second][0] == 'O') {
        if(isSquareEmpty(field, finishCords) && startCords.first == finishCords.first + 1 &&
        (startCords.second == finishCords.second + 1 || startCords.second == finishCords.second - 1)) {
            return true;
        }

        //add kill situation
    }
    if(field->fieldSquares[startCords.first][startCords.second][0] == 'P') {
        if(isSquareEmpty(field, finishCords) && startCords.first == finishCords.first - 1 &&
           (startCords.second == finishCords.second + 1 || startCords.second == finishCords.second - 1)) {
            return true;
        }

        //add kill situation
    }
    return false;
}

void std::checkKings(Field *field) {
    for (int i = 0; i < 8; ++i) {
        if(field->fieldSquares[0][i] == "O") {
            field->fieldSquares[0][i] = "Q";
        }
        if(field->fieldSquares[7][i] == "P") {
            field->fieldSquares[0][i] = "R";
        }
    }
}

pair<int, int> std::stringToCords(string s) {
    int firstCord;
    int secondCord;
    /*
    if(s.length() != 3) {
        return make_pair(-1, -1);
    }
    */
    firstCord = s[0] - 49;
    firstCord = 7 - firstCord;
    secondCord = s[1] - 97;
    if(firstCord < 0 || firstCord > 7 || secondCord < 0 || secondCord > 7) {
        return make_pair(-1, -1);
    }

    return make_pair(firstCord, secondCord);
}

Color std::enemyColor(Color color) {
    if(color == WHITE) {
        return BLACK;
    }
    else {
        return WHITE;
    }
}

Color std::checkPieceColor(Field *field, pair<int, int> cords) {
    string s = field->fieldSquares[cords.first][cords.second];

    if(s[0] == 'O' || s[0] == 'Q') {
        return WHITE;
    }
    if(s[0] == 'P' || s[0] == 'R') {
        return BLACK;
    }
    return WRONG;
}

bool canPieceKill(Field field, pair<int, int> cords) {
    //if{}
    return false;
}


