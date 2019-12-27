//
// Created by oracool on 28.12.2019.
//

#ifndef LAB3_1_IPLAYERMAKER_H
#define LAB3_1_IPLAYERMAKER_H

#include "IPlayer.h"

class IPlayerMaker {
public:
    virtual std::IPlayer* create() const = 0;
    virtual ~IPlayerMaker() = default;
};
#endif //LAB3_1_IPLAYERMAKER_H
