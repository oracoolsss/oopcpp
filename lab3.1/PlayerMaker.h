//
// Created by oracool on 28.12.2019.
//

#ifndef LAB3_1_PLAYERMAKER_H
#define LAB3_1_PLAYERMAKER_H
#include "IPlayerMaker.h"
#include "PlayerFactory.h"

namespace std {
    template <typename T>

    class PlayerMaker: public IPlayerMaker {
    public:
        PlayerMaker(std::string key) {
            PlayerFactory::instance().registerPlayer(key, this);
        }

        virtual IPlayer* create() const {
            return new T();
        }
    };

}
#endif //LAB3_1_PLAYERMAKER_H
