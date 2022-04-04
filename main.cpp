//#include "internal/lasos/Lasos.h"
#include <iostream>
#include "internal/lasos/lang/LasosLang.h"

int main() {
    LasosLang lang = LasosLang();
    std::string str = "(7) + ab + 5";
    lang.read(&str);
}
