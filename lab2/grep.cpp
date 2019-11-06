//
// Created by oracool on 06.11.2019.
//

#include "grep.h"
#include "workWithString.h"
#include <iostream>
#include <string>

using namespace std;

string Grep::operation(string s, string word) {
    WorkWithString obj;
    vector v = obj.vecOfStrings(s);
    for (int i = v.size() - 1; i >= 0; --i) {

        if(v[i].find(word) == string::npos) {
            v.erase(v.begin() + i);
        }
    }
    return obj.stringOfVector(v);
}
