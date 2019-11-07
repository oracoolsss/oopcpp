//
// Created by oracool on 06.11.2019.
//

#ifndef LAB2_ACTION_H
#define LAB2_ACTION_H

#include <iostream>
#include <vector>

class Action {
private:
    int index_;
    std::string operationName_;
    std::vector<std::string> parameters_;
public:
    std::string doWork(std::string s);

    int getIndex() const;

    void setIndex(int index);

    const std::string &getOperationName() const;

    void setOperationName(const std::string &operationName);

    const std::vector<std::string> &getParameters() const;

    void setParameters(const std::vector<std::string> &parameters);

    Action(int index, const std::string &operationName, const std::vector<std::string> &parameters);
};


#endif //LAB2_ACTION_H
