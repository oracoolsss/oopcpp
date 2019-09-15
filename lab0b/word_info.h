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
        float frequency_;
        WordInfo();
        ~WordInfo();

        void addCount();
        void setWord(string s);
        void setCount(int a);
        void setFrequency(float f);

        string getLine() { return word_;}
        int getCount() { return count_;}
        float getFrequency() { return frequency_;}
    };
}