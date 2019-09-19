#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include "word_counter.h"

using namespace std;

int main() {

    string input_file_name = "input.txt";
    string output_file_name = "output.csv";

    WordCounter wc;
    wc.read(input_file_name);
    wc.sortWords();
    wc.write(output_file_name);

    return 0;
}