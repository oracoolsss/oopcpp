#include <utility>

//
// Created by oracool on 04.11.2019.
//

#include "replace.h"
#include <regex>

using namespace std;

string Replace::operation(std::vector<std::string> vec) {
    return regex_replace(vec[0], regex(vec[1]), vec[2]);
}


IWorker* Replace::create() {
    return new Replace();
}
