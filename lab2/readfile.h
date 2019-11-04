//
// Created by oracool on 31.10.2019.
//

#ifndef LAB2_READFILE_H
#define LAB2_READFILE_H

#include "worker.h"

namespace std{
    class ReadFile: public IWorker {
        string operation(string s) override;
    };
}


#endif //LAB2_READFILE_H
