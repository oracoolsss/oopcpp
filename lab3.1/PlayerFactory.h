//
// Created by oracool on 28.12.2019.
//

#ifndef LAB3_1_PLAYERFACTORY_H
#define LAB3_1_PLAYERFACTORY_H

#include <map>
#include "IPlayer.h"
#include "ConsolePlayer.h"
#include "RandomPlayer.h"
#include "SmartRandomPlayer.h"
#include "IPlayerMaker.h"

namespace std {
    class PlayerFactory {
    private:
        map<string, IPlayerMaker*> playerMap_;
    public:
        void registerPlayer(string newPlayerName, IPlayerMaker* newPlayer);
        static PlayerFactory& instance();
        ~PlayerFactory() = default;
        IPlayer* createPlayer(string playerName);
    };
}
#endif //LAB3_1_PLAYERFACTORY_H
