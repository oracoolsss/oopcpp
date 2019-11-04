//
// Created by oracool on 04.11.2019.
//

#ifndef LAB2_REPLACE_H
#define LAB2_REPLACE_H

#include "worker.h"

namespace std {
    class Replace: public IWorker {
    public:
        string operation(string string_to_edit, string pattern, string substring);
    };
}

#endif //LAB2_REPLACE_H
