//
// Created by oracool on 15.11.2019.
//

#ifndef LAB2_ACTIONFACTORY_H
#define LAB2_ACTIONFACTORY_H

#include <map>
#include "actions/worker.h"
#include "actions/readfile.h"
#include "actions/writefile.h"
#include "actions/grep.h"
#include "actions/sort.h"
#include "actions/replace.h"
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

#endif //LAB2_ACTIONFACTORY_H
