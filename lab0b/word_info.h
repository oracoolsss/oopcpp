//
// Created by oracool on 14.09.2019.
//

#ifndef LAB0B_WORD_COUNTER_H
#define LAB0B_WORD_COUNTER_H

#endif //LAB0B_WORD_COUNTER_H

#include <iostream>

namespace std {
    class WordInfo {

    private:
        string word_;
        int count_;
    public:
        WordInfo();
        ~WordInfo();



        string getLine() { return word_;}
        int getWord() { return count_;}

    };
}