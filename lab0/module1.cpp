//
// Created by oracool on 13.09.2019.
//

#include "module1.h"

namespace Module1
{
    std::string getMyName()
    {
        std::string name = "John";
        return name;
    }
}

namespace Module1_P {

    std::string getMyName() {
        std::string name = "Peter";
        return name;
    }

}