//
// Created by Расим Гаджиев on 26.03.2022.
//

#include "LasosLexer.h"
#include <iostream>
#include <algorithm>
#include "../../../pkg/utils/Utils.h"

bool my_isalpha(char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
}


std::string LasosLexer::match_character(std::string *word) {
    word->erase(remove_if(word->begin(), word->end(), isspace), word->end());
    if (*word == " "){
        return "";
    }
    for (const auto &it: this->types) {
        for (const auto &symbol: it.second) {
            if (symbol == *word) {
                return it.first;
            }
        }
    }
    for (auto letter: *word){
        if (std::isalpha(letter) && word->length() == 1) {
            return "LETTER";
        }
    }
    for (auto letter: *word){
        if (std::isdigit(letter) && word->length() == 1) {
            return "DIGIT";
        }
    }
    return "";
}

LasosLexer::LasosLexer() {
    this->map_characters();
}

void LasosLexer::map_characters() {
    this->types["FUNCTIONS"] = this->functions;
    this->types["COMPARATOR_OPERATIONS"] = this->comparator_operations;
    this->types["SIGN_OF"] = this->sign_of;
    this->types["SINGLE_CHAR_KEYWORDS"] = this->single_char_keywords;
}

std::vector<LasosToken> LasosLexer::read(std::string *input) {
    std::string buffer_input;
    std::string buffer_init;
    std::string match_type;
    std::vector<LasosToken> tokens;
    for (auto member: *input) {
        buffer_input += member;
//        std::cout << " - buffer: " << buffer_input << " it: " << member << std::endl;
        match_type = this->match_character(&buffer_input);
        if (!match_type.empty()) {
//            std::cout << "creating token\n";
            tokens.emplace_back(match_type, buffer_input);
            buffer_input = "";
            match_type = "";
        }
    }
    return tokens;
}
