//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_IACTIONMAKER_H
#define TESTLAB2_IACTIONMAKER_H

#include "actions/IWorker.h"

namespace std {
    class IActionMaker {
    public:
        virtual std::IWorker * create() const = 0;
        virtual ~IActionMaker() = default;
    };
}

#endif //TESTLAB2_IACTIONMAKER_H
