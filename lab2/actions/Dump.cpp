//
// Created by oracool on 27.11.2019.
//

#include "Dump.h"
#include "../ActionMaker.h"
#include <fstream>

using namespace std;

static ActionMaker<WriteFile> dumpMaker("dump");

std::string std::Dump::operation(vector<string> vec) {
    if(vec.size() < 2) {
        throw runtime_error("too few arguments for dump operation");
    }
    ofstream output_file;
    output_file.open(vec[1]);
    output_file << vec[0];
    output_file.close();
    return vec[0];
}