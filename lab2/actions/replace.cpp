#include <utility>

//
// Created by oracool on 04.11.2019.
//

#include "replace.h"
#include <regex>
#include "../ActionMaker.h"

using namespace std;

static ActionMaker<Replace> replaceMaker("replace");

string Replace::operation(std::vector<std::string> vec) {
    return regex_replace(vec[0], regex(vec[1]), vec[2]);
}