#include <iostream>
#include "sort.h"
#include <regex>

int main() {
    //test of replace
    std::string s = "tu tu ta\nta ta\nta ta ta";
    std::Sort obj;
    std::cout << obj.operation(s);

    return 0;
}