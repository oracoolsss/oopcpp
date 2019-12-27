//
// Created by oracool on 27.12.2019.
//

#ifndef LAB3_1_SMARTRANDOMPLAYER_H
#define LAB3_1_SMARTRANDOMPLAYER_H

#include "IPlayer.h"
namespace std {
    class SmartRandomPlayer: public IPlayer {
    public:
        Color color;
        Color getColor() override ;
        void makeMove(Field *field) override;
        void setColor(Color color) override;
    };
}

#endif //LAB3_1_SMARTRANDOMPLAYER_H
