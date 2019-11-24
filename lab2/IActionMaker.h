//
// Created by oracool on 23.11.2019.
//
#pragma once

#ifndef LAB2_IACTIONMAKER_H
#define LAB2_IACTIONMAKER_H

#include "actions/worker.h"

class IActionMaker {
public:
    virtual std::IWorker * create() const = 0;
    virtual ~IActionMaker() = default;
};
#endif //LAB2_IACTIONMAKER_H