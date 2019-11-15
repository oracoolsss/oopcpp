//
// Created by oracool on 07.11.2019.
//

#ifndef LAB2_PARSER_H
#define LAB2_PARSER_H

#include <vector>
#include <iostream>

struct DataStruct{
    int index;
    std::string operationName;
    std::vector<std::string> parameters;
};

class Parser {
private:
    std::vector<DataStruct> parsedData;
    std::vector<int> schemeDescription;
public:
    void parse(std::string fileName);
    std::vector<DataStruct> getData();
    std::vector<int> getSchemeDescription();
};


#endif //LAB2_PARSER_H
