//
// Created by oracool on 27.12.2019.
//

#include "SmartRandomPlayer.h"
#include "GameMechanics.h"
#include "PlayerMaker.h"

using namespace std;
static PlayerMaker<SmartRandomPlayer> smartMaker("smart");

pair<pair<int, int>, pair<int, int>> smartRandomMove(Field field, Color color);

Color SmartRandomPlayer::getColor() {
    return this->color;
}

void SmartRandomPlayer::setColor(Color color) {
    this->color = color;
}

void SmartRandomPlayer::makeMove(Field *field) {
    pair<int, int> cords1;
    pair<int, int> cords2;
    pair<pair<int, int>, pair<int, int>> allCords;
    allCords = smartRandomMove(*field, this->color);
    cords1 = allCords.first;
    cords2 = allCords.second;
    cout << cords1.first << " " << cords1.second << endl;
    cout << cords2.first << " " << cords2.second << endl;
    if(cords1.first == -1 || cords2.first == -1) {
        return;
    }
    bool check = isKill(field, cords1, cords2);
    if(check) {
        pair<int, int> deadPiece;
        deadPiece.first = cords1.first + (cords2.first - cords1.first)/2;
        deadPiece.second = cords1.second + (cords2.second - cords1.second)/2;
        field->setStandartSquare(deadPiece);
    }

    field->fieldSquares[cords2.first][cords2.second] = field->fieldSquares[cords1.first][cords1.second];
    field->setStandartSquare(cords1);
    checkKings(field);
}

pair<pair<int, int>, pair<int, int>> smartRandomMove(Field field, Color color) {
    pair<pair<int, int>, pair<int, int>> allCords;
    vector<int> v = randomNumbers();
    if(canPlayerKill(&field, color)) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                pair<int, int> cords = make_pair(i, j);
                if(checkPieceColor(&field, cords)) {
                    if(canPieceKill(field, cords)) {
                        Color enColor = enemyColor(checkPieceColor(&field, cords));
                        if(color == WHITE || isKing(field.fieldSquares[cords.first][cords.second])) {
                            pair<int, int> finCords = make_pair(cords.first - 2, cords.second - 2);
                            if(isInsideField(finCords)) {
                                if(isSquareEmpty(&field, finCords) &&
                                   checkPieceColor(&field, make_pair(cords.first - 1, cords.second + 1)) == enColor) {
                                    return make_pair(cords, finCords);
                                }
                            }

                            finCords = make_pair(cords.first - 2, cords.second + 2);
                            if(isInsideField(finCords)) {
                                if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first - 1, cords.second + 1)) == enColor) {
                                    return make_pair(cords, finCords);
                                }
                            }
                        }

                        if(color == BLACK || isKing(field.fieldSquares[cords.first][cords.second])) {
                            pair<int, int> finCords = make_pair(cords.first + 2, cords.second - 2);
                            if(isInsideField(finCords)) {
                                if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first + 1, cords.second + 1)) == enColor) {
                                    return make_pair(cords, finCords);
                                }
                            }

                            finCords = make_pair(cords.first - 2, cords.second + 2);
                            if(isInsideField(finCords)) {
                                if(isSquareEmpty(&field, finCords) && checkPieceColor(&field, make_pair(cords.first + 1, cords.second + 1)) == enColor) {
                                    return make_pair(cords, finCords);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = v[0]; i <= 7 && i >= 0; i += v[1]) {
        for (int j = v[2]; j <= 7 && j >= 0; j += v[3]) {
            pair<int, int> cords = make_pair(i, j);
            if(checkPieceColor(&field, cords) == color) {
                pair<int, int> finCords = cords;
                if(color == WHITE || isKing(field.fieldSquares[cords.first][cords.second])) {
                    finCords.first -= 1;
                    finCords.second -= 1;
                    if(isInsideField(finCords)) {
                        if(isPossibleToMove(&field, cords, finCords)) {
                            return make_pair(cords, finCords);
                        }
                    }

                    finCords.second += 2;
                    if(isInsideField(finCords)) {
                        if(isPossibleToMove(&field, cords, finCords)) {
                            return make_pair(cords, finCords);
                        }
                    }
                }
                finCords = cords;
                if(color == BLACK || isKing(field.fieldSquares[cords.first][cords.second])) {
                    finCords.first += 1;
                    finCords.second -= 1;
                    if(isInsideField(finCords)) {
                        if(isPossibleToMove(&field, cords, finCords)) {
                            return make_pair(cords, finCords);
                        }
                    }

                    finCords.second += 2;
                    if(isInsideField(finCords)) {
                        if(isPossibleToMove(&field, cords, finCords)) {
                            return make_pair(cords, finCords);
                        }
                    }
                }
            }
        }

    }
    return make_pair(make_pair(-1, -1), make_pair(-1, -1));
}

