//
// Created by oracool on 11.12.2019.
//

#include <iostream>
#include <utility>
#include "ConsolePlayer.h"
#include "GameMechanics.h"

using namespace std;

pair<pair<int, int>, pair<int, int>> readCords(Field field, Color playerColor);

void ConsolePlayer::setColor(Color color) {
    this->color = color;
}

void ConsolePlayer::makeMove(Field *field) {
    pair<int, int> cords1;
    pair<int, int> cords2;
    pair<pair<int, int>, pair<int, int>> allCords;

    //в цикл засунуть
    allCords = readCords(*field, this->color);
    //cout << "checkpoint";

    //проверка хода
    //...
    cords1 = allCords.first;
    cords2 = allCords.second;
    cout << cords1.first << " " << cords1.second << " " << cords2.first << " " << cords2.second << endl;
    field->fieldSquares[cords2.first][cords2.second] = field->fieldSquares[cords1.first][cords1.second];
    field->setStandartSquare(cords1);
    checkKings(field);
    //field->printField();
}

pair<pair<int, int>, pair<int, int>> readCords(Field field, Color playerColor) {
    pair<int, int> cords1;
    pair<int, int> cords2;
    string stringCords1, stringCords2;
    cout << "Type your move!        example: 3a 4b\n";
    bool check = false;
    do {
        cin >> stringCords1 >> stringCords2;
        cords1 = stringToCords(stringCords1);
        cords2 = stringToCords(stringCords2);
        if(cords1.first == -1 || cords2.first == -1 || playerColor != checkPieceColor(field, cords1)) {
            cout << "Wrong coordinates, rewrite it\n";
            cout << field.fieldSquares[cords1.first][cords1.second] << endl;
            check = true;
        }
    }
    while(check);
    return make_pair(cords1, cords2);
}