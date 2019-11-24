//
// Created by oracool on 06.11.2019.
//

#include "grep.h"
#include "workWithString.h"
#include <iostream>
#include <string>
#include "../ActionMaker.h"

using namespace std;

static ActionMaker<Grep> grepMmaker("grep");

string Grep::operation(vector<string> vec) {
    WorkWithString obj;
    vector temporaryVec = obj.vecOfStrings(vec[0]);
    for (int i = temporaryVec.size() - 1; i >= 0; --i) {

        if(temporaryVec[i].find(vec[1]) == string::npos) {
            temporaryVec.erase(temporaryVec.begin() + i);
        }
    }
    return obj.stringOfVector(temporaryVec);
}