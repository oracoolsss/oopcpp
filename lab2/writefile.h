//
// Created by oracool on 03.11.2019.
//

#ifndef LAB2_WRITEFILE_H
#define LAB2_WRITEFILE_H

#include "worker.h"

namespace std {
    class WriteFile: public IWorker {
        string operation(string s, string fileName);
    };
}


#endif //LAB2_WRITEFILE_H
