//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_READFILE_H
#define TESTLAB2_READFILE_H

#include "IWorker.h"
#include <vector>

namespace std{
    class ReadFile: public IWorker {
    public:
        string operation(vector<string> vec) override;
        ReadFile() = default;
        WorkerType getType() override { return IN;}
    };
}


#endif //TESTLAB2_READFILE_H
