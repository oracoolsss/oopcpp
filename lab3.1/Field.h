//
// Created by oracool on 10.12.2019.
//

#ifndef LAB3_1_FIELD_H
#define LAB3_1_FIELD_H

#include <utility>
#include <iostream>
#include "Color.h"
//#include "IPlayer.h"

class Field {
private:

public:
    std::string fieldSquares[8][8];
    Field();
    ~Field() = default;


    void fillWithPieces();
    void setSquare(std::pair<int, int> cords, std::string newValue);
    void setStandartSquare(std::pair<int, int> cords);
    void printField();
    bool isPlayerEliminated(Color color);

};


#endif //LAB3_1_FIELD_H
