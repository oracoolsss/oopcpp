//
// Created by oracool on 03.11.2019.
//

#include "writefile.h"
#include <fstream>

std::string std::WriteFile::operation(std::string s, std::string fileName) {
    ofstream output_file;
    output_file.open(fileName);
    output_file << s;
    output_file.close();
    return "done";
}