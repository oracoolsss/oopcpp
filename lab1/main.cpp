#include <iostream>
#include "tritset.h"

int main() {
    std::Tritset a(100);
    std::Trit tr = std::TRUE;
    std::Trit tr2 = std::TRUE;
    std::cout << (tr == tr2);
    return 0;
}