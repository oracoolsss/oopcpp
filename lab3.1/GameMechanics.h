//
// Created by oracool on 11.12.2019.
//

#ifndef LAB3_1_GAMEMECHANICS_H
#define LAB3_1_GAMEMECHANICS_H

#include "Field.h"
#include "IPlayer.h"
#include "utility"
namespace std {
    class GameMechanics {
    public:

    };

    pair<int, int> stringToCords(string s);
    Color enemyColor(Color color);
    Color checkPieceColor(Field field, pair<int, int> cords);
    void canPlayerKill(Field field, IPlayer* player);
    void canPieceKill(Field field);
    void checkKings(Field* field);
    bool isSquareEmpty(Field field, pair<int, int> cords);
    bool isPieceOnSquare(Field field, pair<int, int> cords, Color color);
    bool isPossibleToMove(Field field, pair<int, int> startCords, pair<int, int> finishCords);
}

#endif //LAB3_1_GAMEMECHANICS_H
