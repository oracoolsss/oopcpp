#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include "word_info.h"

using namespace std;

int FindInVector(vector<WordInfo> string_to_analysis, string search_word) {
    for (int i = 0; i < string_to_analysis.size(); ++i) {
        if(string_to_analysis[i].getLine().compare(search_word) == 0) {
            return i+1;
        }
    }

    return 0;

}

int compare(WordInfo a, WordInfo b) {
    if(b.getFrequency() - a.getFrequency() < 0.0f) {
        return -1;
    }
    else {
        return 1;
    }
}

int main() {

    string input_file_name = "input.txt";
    string output_file_name = "output.csv";
    string input_data;

    ifstream input_file;
    ofstream output_file;

    WordInfo temporary_object;
    string temporary_string = "";
    string separators = "!'?.,;/*-+\n\t ";

    vector<WordInfo> string_to_analysis;

    int total_words_count = 0;

    input_file.open(input_file_name);

    if(!input_file) {
        cout << "file not found" << endl;
        return 0;
    }

    getline(input_file, input_data);

    int iterator = 0;
    int check;

    //text analysis
    while(true) {

        check = 0;

        for (int i = 0; i < separators.length(); ++i) {
            if(input_data[iterator] == separators[i]) {
                check++;
            }
        }

        if(input_data[iterator] == EOF) {
            check = 100;
        }

        if(check > 0) {
            total_words_count++;
            if(FindInVector(string_to_analysis, temporary_string)) {
                string_to_analysis[FindInVector(string_to_analysis, temporary_string) - 1].addCount();
            }
            else if (temporary_string != ""){
                temporary_object.setWord(temporary_string);
                temporary_object.addCount();

                string_to_analysis.push_back(temporary_object);

                temporary_object.setCount(0);
            }

            temporary_string = "";
        }
        else if(input_data[iterator] != 0){
            temporary_string.push_back(input_data[iterator]);
        }

        iterator++;
        if(check == 100) {
            break;
        }
    }

    for (int i = 0; i < string_to_analysis.size(); ++i) {
        float value = (float)string_to_analysis[i].getCount() / (float)total_words_count * 100.0f;
        string_to_analysis[i].setFrequency(value);
    }

    //sort vector by frequency
    sort(string_to_analysis.begin(), string_to_analysis.end(), compare);

    //output to file
    output_file.open(output_file_name);
    output_file << "Cлово,Частота,Частота в %";

    for (int i = 0; i < string_to_analysis.size(); ++i) {
        output_file << endl << string_to_analysis[i].getLine() << "," << string_to_analysis[i].getCount() << "," << string_to_analysis[i].getFrequency();
    }
    return 0;
}