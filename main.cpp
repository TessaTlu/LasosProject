#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include "pkg/profile/profile.h"
#include "pkg/utils/Utils.h"
#include "internal/lasos/token/LasosToken.h"


int main() {
    std::ifstream input("main.py");
    std::string text = text_read(input);
    std::cout << "LasosToken read\n";
    for (auto &token: token_read(text)) {
        std::cout << "[" << token.value << "]" << std::endl;
    };
    input.close();
    return 0;
}
