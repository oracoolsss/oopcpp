//
// Created by oracool on 11.12.2019.
//

#include "GameMechanics.h"
#include <vector>
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
    char currentPiece = field->fieldSquares[startCords.first][startCords.second][0];
    if(currentPiece == 'O' || currentPiece == 'Q' || currentPiece == 'R') {
        if(isSquareEmpty(field, finishCords) && startCords.first == finishCords.first + 1 &&
        (startCords.second == finishCords.second + 1 || startCords.second == finishCords.second - 1)) {
            return true;
        }
    }
    if(currentPiece == 'P' || currentPiece == 'Q' || currentPiece == 'R') {
        if(isSquareEmpty(field, finishCords) && startCords.first == finishCords.first - 1 &&
           (startCords.second == finishCords.second + 1 || startCords.second == finishCords.second - 1)) {
            return true;
        }
    }
    return false;
}

void std::checkKings(Field *field) {
    for (int i = 0; i < 8; ++i) {
        if(field->fieldSquares[0][i][0] == 'O') {
            field->fieldSquares[0][i][0] = 'Q';
        }
        if(field->fieldSquares[7][i][0] == 'P') {
            field->fieldSquares[7][i][0] = 'R';
        }
    }
}

pair<int, int> std::stringToCords(string s) {
    int firstCord;
    int secondCord;
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

bool std::canPlayerKill(Field *field, Color color) {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if((color == checkPieceColor(field, make_pair(i, j))) && canPieceKill(*field, make_pair(i, j))) {
                return true;
            }
        }
    }
    return false;
}

bool std::isInsideField(pair<int, int> cords) {
    if(cords.first < 0 || cords.first > 7) {
        return false;
    }
    if(cords.second < 0 || cords.second > 7) {
        return false;
    }
    return true;
}

bool std::isKing(string s) {
    if(s[0] == 'Q' || s[0] == 'R') {
        return true;
    }
    return false;
}

bool std::canPieceKill(Field field, pair<int, int> cords) {
    Color color = checkPieceColor(&field, cords);
    Color enColor = enemyColor(checkPieceColor(&field, cords));
    if(color == WHITE || isKing(field.fieldSquares[cords.first][cords.second])) {
        pair<int, int> finCords = make_pair(cords.first - 2, cords.second - 2);
        if(isInsideField(finCords)) {
            if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first - 1, cords.second + 1)) == enColor) {
                return true;
            }
        }

        finCords = make_pair(cords.first - 2, cords.second + 2);
        if(isInsideField(finCords)) {
            if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first - 1, cords.second + 1)) == enColor) {
                return true;
            }
        }
    }
    if(color == BLACK || isKing(field.fieldSquares[cords.first][cords.second])) {
        pair<int, int> finCords = make_pair(cords.first + 2, cords.second - 2);
        if(isInsideField(finCords)) {
            if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first + 1, cords.second + 1)) == enColor) {
                return true;
            }
        }
        finCords = make_pair(cords.first - 2, cords.second + 2);
        if(isInsideField(finCords)) {
            if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first - 1, cords.second + 1)) == enColor) {
                return true;
            }
        }
    }

    return false;
}

bool std::isKill(Field *field, pair<int, int> startCords, pair<int, int> finishCords) {
    pair<int, int> between = make_pair(startCords.first + (finishCords.first - startCords.first)/2,
            startCords.second + (finishCords.second - startCords.second)/2);
    return checkPieceColor(field, between) == enemyColor(checkPieceColor(field, startCords));
}

vector<int> std::randomNumbers() {
    vector<int> v;
    v.clear();
    int iFrom, iK, jFrom, jK;
    int variant = 0 + rand() % 3;
    if(variant == 0) {
        iFrom = 0;
        iK = 1;
        jFrom = 0;
        jK = 1;
    }
    else if(variant == 1) {
        iFrom = 0;
        iK = 1;
        jFrom = 7;
        jK = -1;
    }
    else if(variant == 2) {
        iFrom = 7;
        iK = -1;
        jFrom = 0;
        jK = 1;
    }
    else if(variant == 3) {
        iFrom = 7;
        iK = -1;
        jFrom = 7;
        jK = -1;
    }
    else {
        iFrom = 0;
        iK = 0;
        jFrom = 0;
        jK = 0;
    }
    v = {iFrom, iK, jFrom, jK};
    return v;
}


