//
// Created by oracool on 19.09.2019.
//

#ifndef LAB0B_WORD_COUNTER_H
#define LAB0B_WORD_COUNTER_H

#include <iostream>
#include <vector>
#include "word_info.h"

namespace std {
    class WordCounter {

    private:
        vector<WordInfo> string_to_analysis;
        int total_words_count_;
    public:
        WordCounter();
        ~WordCounter();

        void addCount();
        void read(string input_file_name);
        void sortWords();
        void write(string output_file_name);

        int getCount() { return total_words_count_;}
    };
}

#endif //LAB0B_WORD_COUNTER_H
