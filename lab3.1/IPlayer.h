//
// Created by oracool on 10.12.2019.
//

#ifndef LAB3_1_IPLAYER_H
#define LAB3_1_IPLAYER_H

#include <utility>
#include "Field.h"

namespace std {
    enum Color {
        BLACK,
        WHITE,
        WRONG
    };
    class IPlayer {
    public:
        virtual void setColor(Color color) = 0;
        virtual void makeMove(Field *field) = 0;
        virtual ~IPlayer() = default;
    };
}

#endif //LAB3_1_IPLAYER_H
