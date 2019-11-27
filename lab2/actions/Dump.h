//
// Created by oracool on 27.11.2019.
//

#ifndef TESTLAB2_DUMP_H
#define TESTLAB2_DUMP_H

#include "IWorker.h"

namespace std {
    class Dump: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Dump() = default;
        WorkerType getType() override { return INOUT;}
    };
}


#endif //TESTLAB2_DUMP_H
