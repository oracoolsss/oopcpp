//
// Created by oracool on 04.11.2019.
//

#include "sort.h"
#include <vector>
#include <algorithm>
#include "workWithString.h"

using namespace std;

string Sort::operation(vector<string> vec) {
    WorkWithString obj;
    vector<string> v;
    v = obj.vecOfStrings(vec[0]);
    sort(v.begin(), v.end());
    return obj.stringOfVector(v);
}

IWorker* Sort::create() {
    return new Sort();
}


