//
// Created by oracool on 14.09.2019.
//

#include "word_info.h"
#include <iostream>

using namespace std;

WordInfo::WordInfo() {
    count_ = 0;
    word_ = "";
    frequency_ = 0.0f;
}
WordInfo::~WordInfo() = default;

void WordInfo::addCount() {
    count_++;
}

void WordInfo::setWord(string s) {
    word_ = s;
}

void WordInfo::setCount(int a) {
    count_ = a;
}

void WordInfo::setFrequency(float f) {
    frequency_ = f;
}
