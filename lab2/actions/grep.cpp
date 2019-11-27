//
// Created by oracool on 24.11.2019.
//

#include "Grep.h"
#include "WorkWithString.h"
#include <iostream>
#include <string>
#include "../ActionMaker.h"

using namespace std;

static ActionMaker<Grep> grepMaker("grep");

string Grep::operation(vector<string> vec) {
    if(vec.size() < 2) {
        throw runtime_error("too few arguments for grep operation");
    }
    WorkWithString obj;
    vector temporaryVec = obj.vecOfStrings(vec[0]);
    for (int i = temporaryVec.size() - 1; i >= 0; --i) {

        if(temporaryVec[i].find(vec[1]) == string::npos) {
            temporaryVec.erase(temporaryVec.begin() + i);
        }
    }
    return obj.stringOfVector(temporaryVec);
}