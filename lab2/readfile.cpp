//
// Created by oracool on 31.10.2019.
//

#include "readfile.h"
#include <fstream>

std::string std::ReadFile::operation(std::string s) {
    ifstream input_file;

    string return_string = "";
    string input_data;

    input_file.open(s);

    while(getline(input_file, input_data)) {
        return_string += input_data + "\n";
    }

    return return_string;
}