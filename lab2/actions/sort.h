//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_SORT_H
#define TESTLAB2_SORT_H


#include "IWorker.h"

namespace std {
    class Sort: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Sort() = default;
        WorkerType getType() override { return INOUT;}
    };
}



#endif //TESTLAB2_SORT_H
