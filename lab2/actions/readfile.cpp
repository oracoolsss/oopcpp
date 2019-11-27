//
// Created by oracool on 24.11.2019.
//

#include "ReadFile.h"
#include <fstream>
#include "../ActionMaker.h"

using namespace std;

static ActionMaker<ReadFile> readfileMaker("readfile");

string ReadFile::operation(vector<string> vec) {
    if(vec.empty()) {
        throw runtime_error("too few arguments for readfile operation");
    }

    ifstream input_file;
    string return_string = "";
    string input_data;

    input_file.open(vec[1]);

    while(getline(input_file, input_data)) {
        return_string += input_data + "\n";
    }
    input_file.close();
    return return_string;
}