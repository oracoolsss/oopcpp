//
// Created by oracool on 11.12.2019.
//

#ifndef LAB3_1_GAMEMECHANICS_H
#define LAB3_1_GAMEMECHANICS_H

#include <vector>
#include "Field.h"
#include "IPlayer.h"
#include "utility"
namespace std {
    pair<int, int> stringToCords(string s);
    Color enemyColor(Color color);
    Color checkPieceColor(Field *field, pair<int, int> cords);
    bool isKill(Field *field, pair<int, int> startCords, pair<int, int> finishCords);
    bool canPlayerKill(Field *field, Color color);
    bool canPieceKill(Field field, pair<int, int> cords);
    void checkKings(Field *field);
    bool isSquareEmpty(Field *field, pair<int, int> cords);
    bool isPieceOnSquare(Field *field, pair<int, int> cords, Color color);
    bool isPossibleToMove(Field *field, pair<int, int> startCords, pair<int, int> finishCords);
    bool isKing(string s);
    bool isInsideField(pair<int, int> cords);
    vector<int> randomNumbers();
}

#endif //LAB3_1_GAMEMECHANICS_H
