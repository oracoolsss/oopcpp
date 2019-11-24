//
// Created by oracool on 15.11.2019.
//

#include "actionFactory.h"
#include <iostream>

using namespace std;

void ActionFactory:: registerAction(string newActionName, IActionMaker* newAction) {
    if (actionMap_.find(newActionName) != actionMap_.end()){
        throw runtime_error("error, multiple makers for this action name");
    }
    actionMap_[newActionName] = newAction;
}

ActionFactory& ActionFactory::instance() {
    static ActionFactory factory;
    return factory;
}

IWorker* ActionFactory::createAction(std::string actionName) {
    auto action = actionMap_.find(actionName);
    if(action != actionMap_.end()) {
        IActionMaker* actionMaker = action->second;
        return actionMaker->create();
    }
    return NULL;
}