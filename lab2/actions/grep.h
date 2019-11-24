//
// Created by oracool on 06.11.2019.
//

#ifndef LAB2_GREP_H
#define LAB2_GREP_H

#include "worker.h"
#include <vector>
namespace std {
    class Grep: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Grep() = default;
    };
}


#endif //LAB2_GREP_H
