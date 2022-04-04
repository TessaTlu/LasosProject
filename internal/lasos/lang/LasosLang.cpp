//
// Created by Расим Гаджиев on 26.03.2022.
//

#include "LasosLang.h"
#include <iostream>

void LasosLang::read(std::string *word) {
    auto tokens = this->lexer.read(word);
    std::cout<<"Here is token list:...\n";
    for (const LasosToken& it: tokens){
        std::cout<<it.to_string()<<"\n";
    }
}

LasosLang::LasosLang() {
    this->lexer = LasosLexer();
}
