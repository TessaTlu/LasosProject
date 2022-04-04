//
// Created by Расим Гаджиев on 26.03.2022.
//

#include "Utils.h"

bool Utils::is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
