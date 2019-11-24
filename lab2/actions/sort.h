//
// Created by oracool on 04.11.2019.
//

#ifndef LAB2_SORT_H
#define LAB2_SORT_H


#include "worker.h"

namespace std {
    class Sort: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Sort() = default;
    };
}


#endif //LAB2_SORT_H
