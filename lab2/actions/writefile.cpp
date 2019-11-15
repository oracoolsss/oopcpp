#include <utility>

//
// Created by oracool on 03.11.2019.
//

#include "writefile.h"
#include <fstream>

using namespace std;

std::string std::WriteFile::operation(vector<string> vec) {
    ofstream output_file;
    output_file.open(vec[1]);
    output_file << vec[0];
    output_file.close();
    return vec[0];
}

IWorker* WriteFile::create() {
    return new WriteFile();
}
