//
// Created by oracool on 27.12.2019.
//

#ifndef LAB3_1_RANDOMPLAYER_H
#define LAB3_1_RANDOMPLAYER_H

#include "IPlayer.h"
namespace std {
    class RandomPlayer: public IPlayer {
    public:
        Color color;
        Color getColor() override ;
        void makeMove(Field *field) override;
        void setColor(Color color) override;
    };
}


#endif //LAB3_1_RANDOMPLAYER_H
