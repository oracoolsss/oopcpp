//
// Created by oracool on 06.11.2019.
//

#include "Action.h"

using namespace std;

Action::Action(int index, const std::string &opationName, const std::vector<std::string> &parameters) {
    index_ = index;
    operationName_ = opationName;
    parameters_ = parameters;
}

string Action::doWork() {

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
