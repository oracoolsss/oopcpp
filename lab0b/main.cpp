#include <iostream>
#include <fstream>
#include <vector>
#include "word_info.h"

using namespace std;

int main() {
    string input_file_name = "input.txt";
    string output_file_name = "output.csv";
    string input_data;

    ifstream input_file;
    ifstream output_file;

    vector<WordInfo> string_to_analysis;

    input_file.open(input_file_name);

    if(!input_file) {
        cout << "file not found" << endl;
        return -1;
    }

    getline(input_file, input_data);




    return 0;
}