//
// Created by oracool on 03.11.2019.
//

#ifndef LAB2_WRITEFILE_H
#define LAB2_WRITEFILE_H

#include "worker.h"

namespace std {
    class WriteFile: public IWorker {
    public:
        string operation(vector<string> vec) override;
        WriteFile() = default;
    };
}


#endif //LAB2_WRITEFILE_H
