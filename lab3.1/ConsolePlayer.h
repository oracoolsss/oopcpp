//
// Created by oracool on 11.12.2019.
//

#ifndef LAB3_1_CPLAYER_H
#define LAB3_1_CPLAYER_H


#include "IPlayer.h"
namespace std {
    class ConsolePlayer: public IPlayer {
    public:
        Color color;
        void makeMove(Field *field) override;
        void setColor(Color color) override;
    };
}


#endif //LAB3_1_CPLAYER_H
