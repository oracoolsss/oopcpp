#include <utility>

//
// Created by oracool on 03.11.2019.
//

#include "writefile.h"
#include "../ActionMaker.h"
#include <fstream>

using namespace std;

static ActionMaker<WriteFile> writefileMaker("writefile");
static ActionMaker<WriteFile> dumpMaker("dump");


std::string std::WriteFile::operation(vector<string> vec) {
    ofstream output_file;
    output_file.open(vec[1]);
    output_file << vec[0];
    output_file.close();
    return vec[0];
}