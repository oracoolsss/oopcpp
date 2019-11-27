//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_ACTIONFACTORY_H
#define TESTLAB2_ACTIONFACTORY_H

#include <map>
#include "actions/IWorker.h"
#include "actions/Dump.h"
#include "actions/ReadFile.h"
#include "actions/WriteFile.h"
#include "actions/Grep.h"
#include "actions/Sort.h"
#include "actions/Replace.h"
#include "IActionMaker.h"

namespace std {
    class ActionFactory {
    private:
        map<string, IActionMaker*> actionMap_;
    public:
        void registerAction(string newActionName, IActionMaker* newAction);
        static ActionFactory& instance();
        ~ActionFactory() = default;
        IWorker* createAction(string actionName);
    };
}


#endif //TESTLAB2_ACTIONFACTORY_H
