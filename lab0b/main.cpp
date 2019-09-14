#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
//#include <cstring>
#include "word_info.h"

using namespace std;

int main() {
    string input_file_name = "input.txt";
    string output_file_name = "output.csv";
    string input_data;

    ifstream input_file;
    ifstream output_file;

    WordInfo temporary_object;
    string temporary_string = "";
    string separators = "!'?.,;/*-+\n\t ";

    vector<WordInfo> string_to_analysis;

    input_file.open(input_file_name);

    if(!input_file) {
        cout << "file not found" << endl;
        return -1;
    }

    getline(input_file, input_data);

    int iterator = 0;
    while(input_data[iterator] != EOF) {
        for (int i = 0; i < separators.length(); ++i) {
            if(input_data[iterator] == separators[i]) {
                //сделать поиск в векторе, добавление значений
            }
            else {
                temporary_string.push_back(input_data[iterator]);
            }
        }
    }

    //написать запись в файл

    return 0;
}