//
// Created by oracool on 07.11.2019.
//

#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H

#include "action.h"
#include <vector>

class Parser {
private:
    std::vector<Action> actions_;
public:
    void start(std::string fileName);
};


#endif //LAB2_PARSER_H
