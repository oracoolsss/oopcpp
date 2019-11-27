//
// Created by oracool on 24.11.2019.
//

#ifndef TESTLAB2_IWORKER_H
#define TESTLAB2_IWORKER_H

#include <iostream>
#include <vector>

namespace std {

    enum WorkerType {
        IN,
        OUT,
        INOUT
    };


    class IWorker {
    public:
        virtual string operation(vector<string> vec) = 0;
        virtual ~IWorker() = default;
        virtual WorkerType getType() = 0;
    };
}

#endif //TESTLAB2_IWORKER_H
