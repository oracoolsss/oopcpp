//
// Created by oracool on 19.09.2019.
//

#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include "word_counter.h"

int FindInVector(std::vector<std::WordInfo> string_to_analysis, std::string search_word) {
    for (int i = 0; i < string_to_analysis.size(); ++i) {
        if(string_to_analysis[i].getLine().compare(search_word) == 0) {
            return i+1;
        }
    }

    return 0;

}

int compare(std::WordInfo a,std::WordInfo b) {
    return b.getCount() < a.getCount();
}

std::WordCounter::WordCounter() {
    total_words_count_ = 0;
}

void std::WordCounter::addCount() {
    total_words_count_++;
}

void std::WordCounter::read(std::string input_file_name) {
    ifstream input_file;

    WordInfo temporary_object;
    string temporary_string = "";
    string input_data;

    //vector<WordInfo> string_to_analysis;

    input_file.open(input_file_name);
    //check file

    getline(input_file, input_data);


    int iterator = 0;
    int check;

    //text analysis
    while(true) {

        check = 0;
        if(!isalnum(input_data[iterator])) {
            check++;
        }

        if(input_data[iterator] == EOF) {
            check = 100;
        }

        if(check > 0) {

            this->addCount();

            if(FindInVector(this->string_to_analysis, temporary_string)) {
                this->string_to_analysis[FindInVector(this->string_to_analysis, temporary_string) - 1].addCount();
            }
            else if (!temporary_string.empty()){
                temporary_object.setWord(temporary_string);
                temporary_object.addCount();

                this->string_to_analysis.push_back(temporary_object);

                temporary_object.setCount(0);
            }

            temporary_string = "";
        }
        else if(input_data[iterator] != 0){
            temporary_string.push_back(input_data[iterator]);
        }

        if(check == 100 || iterator == input_data.length()) {
            break;
        }

        iterator++;
    }

    for (int i = 0; i < this->string_to_analysis.size(); ++i) {
        float value = (float)this->string_to_analysis[i].getCount() / (float)this->getCount() * 100.0f;
        this->string_to_analysis[i].setFrequency(value);
    }
    sort(this->string_to_analysis.begin(), this->string_to_analysis.end(), compare);
}

void std::WordCounter::sortWords() {
    sort(this->string_to_analysis.begin(), this->string_to_analysis.end(), compare);
}

void std::WordCounter::write(std::string output_file_name) {
    ofstream output_file;
    output_file.open(output_file_name);
    output_file << "Cлово,Частота,Частота в %";

    for (int i = 0; i < this->string_to_analysis.size(); ++i) {
        output_file << endl << this->string_to_analysis[i].getLine() << "," << this->string_to_analysis[i].getCount() << "," << this->string_to_analysis[i].getFrequency();
    }
}

std::WordCounter::~WordCounter() = default;

