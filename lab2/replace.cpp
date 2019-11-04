//
// Created by oracool on 04.11.2019.
//

#include "replace.h"
#include <regex>

std::string std::Replace::operation(std::string string_to_edit, std::string pattern, std::string substring) {
    return std::regex_replace(string_to_edit, regex(pattern), substring);
}
