//
// Created by oracool on 23.11.2019.
//

#pragma once

#include "IActionMaker.h"
#include "actionFactory.h"

namespace std {
    template <typename T>
    class ActionMaker : public IActionMaker {
    public:
        explicit ActionMaker(const string actionName){
            ActionFactory::instance().registerAction(actionName, this);
        }

        virtual std::IWorker * create() const {
            return new T();
        }
    };
}