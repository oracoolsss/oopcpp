//
// Created by oracool on 06.11.2019.
//

#include "workWithString.h"
#include <vector>
#include <iostream>

using namespace std;

vector<string> WorkWithString::vecOfStrings(string s) {
    vector<string> vec;
    string tempString = "";
    for (int i = 0; i <= s.length(); ++i) {
        if(s[i] == '\n' || i == s.length()) {
            vec.push_back(tempString);
            tempString = "";
        }
        else {
            tempString.push_back(s[i]);
        }
    }
    return vec;
}

string WorkWithString::stringOfVector(std::vector<std::string> vec) {
    string s = "";
    for(int i = 0; i < vec.size(); i++) {
        s += vec[i] + "\n";
    }
    return s;
}