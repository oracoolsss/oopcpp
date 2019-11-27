//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_REPLACE_H
#define TESTLAB2_REPLACE_H

#include "IWorker.h"
#include <vector>

namespace std {
    class Replace: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Replace() = default;
        WorkerType getType() override { return INOUT;}
    };
}


#endif //TESTLAB2_REPLACE_H
