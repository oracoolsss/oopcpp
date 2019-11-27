//
// Created by oracool on 24.11.2019.
//

#include "Replace.h"
#include <regex>
#include "../ActionMaker.h"

using namespace std;

static ActionMaker<Replace> replaceMaker("replace");

string Replace::operation(std::vector<std::string> vec) {
    if(vec.size() < 3) {
        throw runtime_error("too few arguments for replace operation");
    }

    return regex_replace(vec[0], regex(vec[1]), vec[2]);
}