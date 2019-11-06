//
// Created by oracool on 06.11.2019.
//

#ifndef LAB2_GREP_H
#define LAB2_GREP_H

#include "worker.h"

namespace std {
    class Grep: public IWorker {
    public:
        string operation(string s, string word);
    };
}


#endif //LAB2_GREP_H
