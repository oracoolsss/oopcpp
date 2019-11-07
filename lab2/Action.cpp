//
// Created by oracool on 06.11.2019.
//

#include "action.h"
#include "readfile.h"
#include "writefile.h"
#include "grep.h"
#include "sort.h"
#include "replace.h"

using namespace std;

Action::Action(int index, const std::string &operationName, const std::vector<std::string> &parameters) {
    index_ = index;
    operationName_ = operationName;
    parameters_ = parameters;
}
/*
1 readfile <filename>  – считывание текстового файла в память, целиком.
2 writefile <filename> – запись текста в файл.
3 grep <word> – выбор из входного текста строк, разделенных символами переноса строки, содержащих заданное слово <word>.
4 sort – лексикографическая сортировка входного набора строк.
5 replace <word1> <word2> – замена слова word1 словом word2 во входном тексте.
6 dump <filename> - сохранить пришедший текст в указанном файле и передать дальше.
*/
string actionReadfile(string fileName) {
    ReadFile obj;
    return obj.operation(fileName);
}
string actionWritefile(string s, string fileName) {
    WriteFile obj;
    return obj.operation(s, fileName);
}
string actionGrep(string s, string word) {
    Grep obj;
    return obj.operation(s, word);
}
string actionSort(string s) {
    Sort obj;
    return obj.operation(s);
}
string actionReplace(string s, string pattern, string substring) {
    Replace obj;
    return obj.operation(s, pattern, substring);
}
string actionDump(string s, string fileName) {
    WriteFile obj;
    return obj.operation(s, fileName);
}


string Action::doWork(string s) {
    if(operationName_ == "readfile") {
        return actionReadfile(parameters_[0]);
    }
    else if(operationName_ == "writefile") {
        return actionWritefile(s, parameters_[0]);
    }
    else if(operationName_ == "grep") {
        return actionGrep(s, parameters_[0]);
    }
    else if(operationName_ == "sort") {
        return actionSort(s);
    }
    else if(operationName_ == "replace") {
        return actionReplace(s, parameters_[0], parameters_[1]);
    }
    else if(operationName_ == "dump") {
        return actionDump(s, parameters_[0]);
    }
    return "error";
}

int Action::getIndex() const {
    return index_;
}

void Action::setIndex(int index) {
    Action::index_ = index;
}

const std::string &Action::getOperationName() const {
    return operationName_;
}

void Action::setOperationName(const std::string &opationName) {
    Action::operationName_ = opationName;
}

const std::vector<std::string> &Action::getParameters() const {
    return parameters_;
}

void Action::setParameters(const std::vector<std::string> &parameters) {
    Action::parameters_ = parameters;
}
