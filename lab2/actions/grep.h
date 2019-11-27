//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_GREP_H
#define TESTLAB2_GREP_H

#include "IWorker.h"
#include <vector>
namespace std {
    class Grep: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Grep() = default;
        WorkerType getType() override { return INOUT;}
    };
}



#endif //TESTLAB2_GREP_H
