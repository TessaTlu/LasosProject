//
// Created by Расим Гаджиев on 26.03.2022.
//

#ifndef LASOSPROJECT_LASOSLANG_H
#define LASOSPROJECT_LASOSLANG_H
#include <map>
#include <functional>
#include "../lexer/LasosLexer.h"


class LasosLang {
private:
    LasosLexer lexer;
public:
    LasosLang();
    void read(std::string *word);
};


#endif //LASOSPROJECT_LASOSLANG_H
