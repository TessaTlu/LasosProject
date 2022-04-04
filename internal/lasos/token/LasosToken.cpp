//
// Created by Расим Гаджиев on 26.03.2022.
//

#include "LasosToken.h"

#include <utility>

std::string LasosToken::to_string() const {
    return "LasosToken [type]: " + this->type + " [value]: " + this->value;
}

LasosToken::LasosToken(std::string type, std::string value) {
    this->type = std::move(type);
    this->value = std::move(value);
}
