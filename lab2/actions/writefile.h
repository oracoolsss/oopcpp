//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_WRITEFILE_H
#define TESTLAB2_WRITEFILE_H

#include "IWorker.h"

namespace std {
    class WriteFile: public IWorker {
    public:
        string operation(vector<string> vec) override;
        WriteFile() = default;
        WorkerType getType() override { return OUT;}
    };
}


#endif //TESTLAB2_WRITEFILE_H
