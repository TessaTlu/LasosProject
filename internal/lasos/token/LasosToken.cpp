#include "LasosToken.h"
#include <vector>
#include <unordered_map>
#include <string_view>
#include <regex>
#include <string>
#include <iostream>

#include <boost/regex.hpp>



bool is_keyword(const std::string_view &lexem) {
    return KEYWORDS.contains(lexem);
}

bool is_operator(const std::string_view &lexem) {
    return OPERATORS.contains(lexem);
}

bool is_assign_operator(const std::string_view &lexem) {
    return ASSIGN_OPERATOR.contains(lexem);
}

bool is_brace(const std::string_view &lexem) {
    return BRACES.contains(lexem);
}

bool is_separator(const std::string_view &lexem) {
    return SEPARATORS.contains(lexem);
}

bool is_identifier(const std::string_view &lexem) {
    return boost::regex_match(std::string(lexem), IDENTIFIER_REGEX);
}

bool is_string_constant(const std::string_view &lexem) {
    return boost::regex_match(std::string(lexem), STRING_CONSTANT_REGEX);
}

bool is_number_constant(const std::string_view &signature) {
    return boost::regex_match(std::string(signature), NUMBER_CONSTANT_REGEX);
}


std::optional<LasosToken::LasosType> token_type_read(std::string_view signature) {

    if (is_keyword(signature)) {
        return KEYWORDS.at(signature);
    } else if (is_brace(signature)) {
        return BRACES.at(signature);
    } else if (is_assign_operator(signature)) {
        return ASSIGN_OPERATOR.at(signature);
    } else if (is_separator(signature)) {
        return SEPARATORS.at(signature);
    } else if (is_operator(signature)) {
        return OPERATORS.at(signature);
    } else if (is_identifier(signature)) {
        return LasosToken::LasosType::IDENTIFIER;
    } else if (is_string_constant(signature)) {
        return LasosToken::LasosType::STRING_CONSTANT;
    } else if (is_number_constant(signature)) {
        return LasosToken::LasosType::NUMBER_CONSTANT;
    }
    return std::nullopt;
}


std::optional<LasosToken> token_single_read(std::string_view& text) {

    enum class State {
        WAITING_FOR_SUCCESS,
        WAITING_FOR_UNSUCCESS,
    };

    State current_state = State::WAITING_FOR_SUCCESS;
    LasosToken::LasosType last_matched = LasosToken::LasosType::UNDEFINED;

    for (int j = 1; j <= text.size(); j++) {

        auto current_match = token_type_read(text.substr(0, j));

        if (current_match.has_value()) {
            if (current_state == State::WAITING_FOR_SUCCESS) {
                current_state = State::WAITING_FOR_UNSUCCESS;
            }
            last_matched = current_match.value();
        } else {
            if (current_state == State::WAITING_FOR_UNSUCCESS) {
                LasosToken t(last_matched, text.substr(0, j - 1));
                text.remove_prefix(j - 1);
                return t;
            }
        }

//        std::cout << str.substr(0, j) << std::endl;
//        auto type = token_type_read(str.substr(0, j));

    }

    if (last_matched != LasosToken::LasosType::UNDEFINED && current_state == State::WAITING_FOR_UNSUCCESS) {
        LasosToken t(last_matched, text);
        text.remove_prefix(text.size());
        return t;
    }

    return std::nullopt;
}

std::vector<LasosToken> token_read(std::string_view text) {
    std::vector<LasosToken> result;

    int line_number = 1;

    do {
        auto token = token_single_read(text);
        if (token.has_value()) {
            if (token.value().type == LasosToken::LasosType::ENDLINE) {
                line_number++;
            } else {
                if (token.value().type != LasosToken::LasosType::TAB && token.value().type != LasosToken::LasosType::SPACE)
                    result.emplace_back(token.value());
            }
        } else {
            std::cerr << "Problem on line " << line_number << std::endl;
            break;
        }

    } while (!text.empty());


    return result;
}

std::ostream &operator<<(std::ostream &out, const LasosToken &t) {
    return out;
}
