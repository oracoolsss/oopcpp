//
// Created by oracool on 04.11.2019.
//

#ifndef LAB2_REPLACE_H
#define LAB2_REPLACE_H

#include "worker.h"
#include <vector>

namespace std {
    class Replace: public IWorker {
    public:
        string operation(vector<string> vec) override;
        Replace() = default;
    };
}

#endif //LAB2_REPLACE_H
