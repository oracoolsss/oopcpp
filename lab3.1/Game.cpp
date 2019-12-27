//
// Created by oracool on 11.12.2019.
//

#include "Game.h"
#include "PlayerFactory.h"
#include <iostream>
using namespace std;

void Game::play() {
    string p1s, p2s;
    cout << "Types: console, random, smart";
    cout << "Write type of white player\n";
    cin >> p1s;
    cout << "Write type of black player\n";
    cin >> p2s;
    cout << p1s << p2s;
    PlayerFactory playerFactory = PlayerFactory::instance();
    IPlayer* player1 = playerFactory.createPlayer(p1s);
    IPlayer* player2 = playerFactory.createPlayer(p2s);

    player1->setColor(WHITE);
    player2->setColor(BLACK);
    Field f;
    f.fillWithPieces();

    f.printField();
    while(1) {
        player1->makeMove(&f);
        f.printField();
        if(isItWin(f)) {
            break;
        }
        player2->makeMove(&f);
        f.printField();
        if(isItWin(f)) {
            break;
        }
    }
}

bool Game::isItWin(Field field) {
    int w = 0;
    int b = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(checkPieceColor(&field, make_pair(i,j)) == 0) {
                b++;
            }
            if(checkPieceColor(&field, make_pair(i,j)) == 1) {
                w++;
            }
        }
    }
    if(w == 0) {
        cout << "black won";
        return true;
    }
    if(b == 0) {
        cout << "white won";
        return true;
    }
    return false;
}
