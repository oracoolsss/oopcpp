//
// Created by oracool on 24.11.2019.
//

#include "WriteFile.h"
#include "../ActionMaker.h"
#include <fstream>

using namespace std;

static ActionMaker<WriteFile> writefileMaker("writefile");

std::string std::WriteFile::operation(vector<string> vec) {
    if(vec.size() < 2) {
        throw runtime_error("too few arguments for writefile operation");
    }

    ofstream output_file;
    output_file.open(vec[1]);
    output_file << vec[0];
    output_file.close();
    return "done";
}