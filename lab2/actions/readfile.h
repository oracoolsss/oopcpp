//
// Created by oracool on 31.10.2019.
//

#ifndef LAB2_READFILE_H
#define LAB2_READFILE_H

#include "worker.h"
#include <vector>

namespace std{
    class ReadFile: public IWorker {
    public:
        string operation(vector<string> vec) override;
        static IWorker* create();
    };
}


#endif //LAB2_READFILE_H
