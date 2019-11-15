//
// Created by oracool on 15.11.2019.
//

#include "actionFactory.h"
#include <iostream>

using namespace std;

void ActionFactory::addAction(string newActionName, IWorker* newAction) {
    actionMap_[newActionName] = newAction;
}

ActionFactory::ActionFactory() {
    IWorker* grepObj = Grep::create();
    addAction("grep", grepObj);
    IWorker* readObj = ReadFile::create();
    addAction("readfile", readObj);
    IWorker* replaceObj = Replace::create();
    addAction("replace", replaceObj);
    IWorker* sortObj = Sort::create();
    addAction("sort", sortObj);
    IWorker* dumpObj = WriteFile::create();
    addAction("writefile", dumpObj);
    IWorker* writeObj = WriteFile::create();
    addAction("dump", writeObj);

}

IWorker* ActionFactory::createAction(std::string actionName) {
    auto action = actionMap_.find(actionName);
    if(action != actionMap_.end()) {
        return action->second;
    }
    return NULL;
}