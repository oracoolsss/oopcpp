//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_ACTIONMAKER_H
#define TESTLAB2_ACTIONMAKER_H

#include "IActionMaker.h"
#include "ActionFactory.h"

namespace std {
    template <typename T>

    class ActionMaker: public IActionMaker {
    public:
        ActionMaker(std::string key) {
            ActionFactory::instance().registerAction(key, this);
        }

        virtual IWorker* create() const {
            return new T();
        }
    };

}
#endif //TESTLAB2_ACTIONMAKER_H
