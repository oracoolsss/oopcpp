#include <utility>
//
// Created by oracool on 07.11.2019.
//


#include "parser.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

DataStruct dataToStruct(int ind, string str, vector<string> vec) {
    DataStruct obj;
    obj.index = ind;
    obj.operationName = move(str);
    obj.parameters = move(vec);
    return obj;
}

string wordFromString(int* pos, string s) {
    string returnString = "";
    while(s[*pos] != ' ' && *pos < s.size()) {
        returnString.push_back(s[*pos]);
        *pos += 1;
    }
    *pos += 1;
    return returnString;
}

void Parser::parse(std::string fileName) {
    const string err = "error";
    ifstream input_file;
    string tempString;
    string workString = "";

    int index;
    vector<int> writeFileIndex;
    vector<int> readFileIndex;

    string operationName;
    vector<string> parameters;

    input_file.open(fileName);

    input_file >> tempString;
    if(tempString != "desc") {
        cout << err << endl << tempString << endl;
        return;
    }
    parsedData.clear();
    schemeDescription.clear();
    getline(input_file, tempString);
    do {
        string strIndex = "";
        getline(input_file, tempString);
        int iterator = 0;
        strIndex = wordFromString(&iterator, tempString);

        if(strIndex != "csed") {
            try {
                index = stoi(strIndex);
            }
            catch(std::invalid_argument r) {
                cout << err << " wrong action index: " << strIndex << endl;
            }
            operationName = wordFromString(&iterator, tempString);
            operationName = wordFromString(&iterator, tempString);

            while(iterator < tempString.size()) {
                parameters.push_back(wordFromString(&iterator, tempString));
            }
            parsedData.push_back(dataToStruct(index, operationName, parameters));
            operationName.clear();
            parameters.clear();
        }
    }
    while(tempString != "csed");

    while(input_file >> tempString) {
        if(tempString != "->") {
            schemeDescription.push_back(stoi(tempString));
        }
    }
}

vector<DataStruct> Parser::getData() {
    return parsedData;
}

vector<int> Parser::getSchemeDescription() {
    return schemeDescription;
}


