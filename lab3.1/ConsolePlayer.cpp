//
// Created by oracool on 11.12.2019.
//

#include <iostream>
#include <utility>
#include "ConsolePlayer.h"
#include "GameMechanics.h"
#include "PlayerMaker.h"

using namespace std;
static PlayerMaker<ConsolePlayer> consoleMaker("console");

pair<pair<int, int>, pair<int, int>> readCords(Field *field, Color playerColor);

void ConsolePlayer::setColor(Color color) {
    this->color = color;
}

void ConsolePlayer::makeMove(Field *field) {
    pair<int, int> cords1;
    pair<int, int> cords2;
    pair<pair<int, int>, pair<int, int>> allCords;
    cout << "Type your move!        example: 3a 4b\n";

    bool check = false;
    bool check1, check2;
    while(!check) {
        allCords = readCords(field, this->color);
        cords1 = allCords.first;
        cords2 = allCords.second;

        check1 = canPieceKill(*field, cords1);
        check2 = isKill(field, cords1, cords2);
        check = isPieceOnSquare(field, cords1, this->color) && (isPossibleToMove(field, cords1, cords2) || check1);

        if(!check) {
            cout << "rewrite your move(wrong move)" << endl;
        }

        if(check) {
            if(check1 != check2) {
                cout << "rewrite your move (wrong kill situation)" << endl;
                check = !check;
            }
        }

        if(canPlayerKill(field, this->getColor()) && !check2) {
            cout << "rewrite your move, you should kill" << endl;
            check = false;
        }

    }

    if(check2) {
        pair<int, int> deadPiece;
        deadPiece.first = cords1.first + (cords2.first - cords1.first)/2;
        deadPiece.second = cords1.second + (cords2.second - cords1.second)/2;
        field->setStandartSquare(deadPiece);
    }


    field->fieldSquares[cords2.first][cords2.second] = field->fieldSquares[cords1.first][cords1.second];
    field->setStandartSquare(cords1);
    checkKings(field);
}

Color ConsolePlayer::getColor() {
    return this->color;
}

pair<pair<int, int>, pair<int, int>> readCords(Field *field, Color playerColor) {
    pair<int, int> cords1;
    pair<int, int> cords2;
    string stringCords1, stringCords2;

    bool check = false;
    while(!check) {
        cin >> stringCords1 >> stringCords2;
        cords1 = stringToCords(stringCords1);
        cords2 = stringToCords(stringCords2);
        if(cords1.first == -1 || cords2.first == -1 || playerColor != checkPieceColor(field, cords1)
           || !isSquareEmpty(field, cords2)) {
            cout << "Wrong coordinates, rewrite it\n";
            check = false;
        }
        else {
            check = true;
        }
    }
    return make_pair(cords1, cords2);
}