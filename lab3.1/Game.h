//
// Created by oracool on 11.12.2019.
//

#ifndef LAB3_1_GAME_H
#define LAB3_1_GAME_H

#include "ConsolePlayer.h"
#include "RandomPlayer.h"
#include "SmartRandomPlayer.h"
#include "Field.h"
#include "GameMechanics.h"

using namespace std;
class Game {
public:
    void play();

private:
    bool isItWin(Field field);
};


#endif //LAB3_1_GAME_H
