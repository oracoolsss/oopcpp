//
// Created by oracool on 15.11.2019.
//

#include "workFlow.h"
#include "parser.h"
#include "actionFactory.h"

using namespace std;

void WorkFlow::start(std::string fileName) {
    Parser parser;
    vector<DataStruct> parsedData;
    vector<int> schemeDescription;
    string workString;
    ActionFactory actionFactory = ActionFactory::instance();

    parser.parse(fileName);
    parsedData = parser.getData();
    schemeDescription = parser.getSchemeDescription();


    for (int i = 0; i < parsedData.size(); ++i) {
        if(parsedData[i].index == schemeDescription[0]) {
            if(parsedData[i].operationName != "readfile") {
                cout << "wrong scheme";
                return;
            }
        }
        if(parsedData[i].index == schemeDescription[schemeDescription.size()-1]) {
            if(parsedData[i].operationName != "writefile") {
                cout << "wrong scheme";
                return;
            }
        }
    }


    for (int i = 0; i < schemeDescription.size(); ++i) {
        for (int j = 0; j < parsedData.size(); ++j) {
            if(schemeDescription[i] == parsedData[j].index) {
                IWorker* command = actionFactory.createAction(parsedData[j].operationName);
                workString = command->operation(parsedData[j].parameters);
                delete command;
                break;
            }
        }
    }
}
