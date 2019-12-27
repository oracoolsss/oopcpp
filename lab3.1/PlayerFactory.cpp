//
// Created by oracool on 28.12.2019.
//

#include "PlayerFactory.h"
#include <iostream>
using namespace std;
void PlayerFactory:: registerPlayer(string newPlayerName, IPlayerMaker* newPlayer) {
    if (playerMap_.find(newPlayerName) != playerMap_.end()){
        throw runtime_error("error, multiple makers for this action name");
    }
    playerMap_[newPlayerName] = newPlayer;
}

PlayerFactory& PlayerFactory::instance() {
    static PlayerFactory factory;
    return factory;
}

IPlayer* PlayerFactory::createPlayer(std::string playerName) {
    auto player = playerMap_.find(playerName);

    if(player != playerMap_.end()) {
        IPlayerMaker* actionMaker = player->second;
        return actionMaker->create();
    }
    IPlayerMaker* actionMaker = player->second;
    return actionMaker->create();

}