//
// Created by oracool on 07.11.2019.
//


#include "parser.h"
#include "action.h"
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

void Parser::start(std::string fileName) {
    const string err = "error";
    ifstream input_file;
    string tempString;
    string workString = "";

    int index;
    vector<int> writeFileIndex;
    vector<int> readFileIndex;
    string operationName;
    vector<string> parameters;

    vector<int> schemeDescription;

    //int tempInt;
    input_file.open(fileName);

    input_file >> tempString;
    if(tempString != "desc") {
        cout << err;
        return;
    }

    do {
        input_file >> tempString;
        if(tempString != "csed") {
            //cout << tempString << "\n";
            index = stoi(tempString);
            input_file >> tempString;
            input_file >> operationName;

            if(operationName == "readfile" || operationName == "writefile") {
                input_file >> tempString;
                parameters.push_back(tempString);
                actions_.emplace_back(index, operationName, parameters);
                parameters.clear();
                if(operationName == "readfile") {
                    readFileIndex.push_back(index);
                }
                else {
                    writeFileIndex.push_back(index);
                }

            }
            else if(operationName == "grep" || operationName == "dump") {
                input_file >> tempString;
                parameters.push_back(tempString);
                actions_.emplace_back(index, operationName, parameters);
                parameters.clear();
            }
            else if(operationName == "sort") {
                parameters.push_back(tempString);
                actions_.emplace_back(index, operationName, parameters);
                parameters.clear();
            }
            else if(operationName == "replace") {
                for (int i = 0; i < 2; ++i) {
                    input_file >> tempString;
                    parameters.push_back(tempString);
                }
                actions_.emplace_back(index, operationName, parameters);
                parameters.clear();
            }
        }
    }
    while(tempString != "csed");

    while(input_file >> tempString) {
        if(tempString != "->") {
            schemeDescription.push_back(stoi(tempString));
        }
    }

    for (int j = 0; j < readFileIndex.size(); ++j) {
        if(schemeDescription[0] == readFileIndex[j]) {
            return;
        }
    }
    for (int j = 0; j < writeFileIndex.size(); ++j) {
        if (schemeDescription[schemeDescription.size() - 1] == writeFileIndex[j]) {
            return;
        }
    }

    for (int k = 0; k < schemeDescription.size(); ++k) {
        int i = -1;
        for (int j = 0; j < actions_.size(); ++j) {
            if(actions_[j].getIndex() == schemeDescription[k]) {
                i = j;
                break;
            }
        }
        if(i == -1) {
            return;
        }
        workString = actions_[i].doWork(workString);
    }

}