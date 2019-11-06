//
// Created by oracool on 04.11.2019.
//

#include "sort.h"
#include <vector>
#include <algorithm>
#include "workWithString.h"

using namespace std;

string Sort::operation(string s) {
    WorkWithString obj;
    vector<string> v;
    v = obj.vecOfStrings(s);
    sort(v.begin(), v.end());
    return obj.stringOfVector(v);
}
