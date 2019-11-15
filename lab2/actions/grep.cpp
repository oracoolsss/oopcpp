//
// Created by oracool on 06.11.2019.
//

#include "grep.h"
#include "workWithString.h"
#include <iostream>
#include <string>

using namespace std;

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

IWorker* Grep::create() {
    return new Grep();
}