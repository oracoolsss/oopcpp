#include <iostream>
#include "replace.h"
#include <regex>

int main() {
    //test of replace
    std::string s = "tu tu ta ta ta";
    std::Replace obj;
    std::cout << obj.operation(s, "ta", "aa") << std::endl;
    std::cout << std::regex_replace(s, std::regex("ta"), "aa");

    return 0;
}