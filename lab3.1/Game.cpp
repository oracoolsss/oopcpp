//
// Created by oracool on 11.12.2019.
//

#include "Game.h"
using namespace std;

void Game::play() {
    ConsolePlayer p;
    Field f;
    f.fillWithPieces();
    p.setColor(WHITE);
    for (int i = 0; i < 5; ++i) {
        f.printField();
        p.makeMove(&f);
    }
}

bool Game::isItDraw(Field field) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

        }
    }
    return false;
}
