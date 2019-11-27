//
// Created by oracool on 24.11.2019.
//

#include "Sort.h"
#include <vector>
#include <algorithm>
#include "workWithString.h"
#include "../ActionMaker.h"

using namespace std;

static ActionMaker<Sort> sortMaker("sort");

string Sort::operation(vector<string> vec) {
    if(vec.empty()) {
        throw runtime_error("too few arguments for sort operation");
    }

    WorkWithString obj;
    vector<string> v;
    v = obj.vecOfStrings(vec[0]);
    sort(v.begin(), v.end());
    return obj.stringOfVector(v);
}