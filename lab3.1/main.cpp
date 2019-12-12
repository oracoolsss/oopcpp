#include <iostream>
#include <utility>
#include <cstdio>
#include "Field.h"
#include "GameMechanics.h"
#include "Game.h"

using namespace std;

int main() {
    /*
    Field f = Field();
    GameMechanics gm;
    f.printField();
    f.setSquare(make_pair(0, 0), "O");
    checkKings(&f);
    f.printField();
    */
    Game game;
    game.play();
}