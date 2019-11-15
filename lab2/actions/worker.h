//
// Created by oracool on 31.10.2019.
//
#pragma once
#ifndef LAB2_WORKER_H
#define LAB2_WORKER_H

#endif //LAB2_WORKER_H

#include <vector>
#include <iostream>

namespace std {
    class IWorker {
    public:
        virtual string operation(vector<string> vec) = 0;
        virtual ~IWorker() = default;
    };
}