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

namespace std {
    class ActionFactory {
    private:
        map<string, IWorker*> actionMap_;
        void addAction(string newActionName, IWorker* newAction);

    public:
        ActionFactory();
        ~ActionFactory() {actionMap_.clear();}
        IWorker* createAction(string actionName);
    };
}


#endif //LAB2_ACTIONFACTORY_H
