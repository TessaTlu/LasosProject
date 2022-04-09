#ifndef LASOS_TOKEN_H
#define LASOS_TOKEN_H

#include <unordered_map>
#include <vector>
#include <string_view>
#include <regex>
#include <boost/regex.hpp>

struct LasosToken {

    enum class LasosType {
        FOR_KEYWORD,
        WHILE_KEYWORD,
        STRUCT_KEYWORD,
        IF_KEYWORD,
        ELSE_KEYWORD,
        LOAD_KEYWORD,
        OPERATOR,
        ASSIGN_OPERATOR,

        CURLY_OPEN_BRACE,
        CURLY_CLOSE_BRACE,
        OPEN_PARENTHESIS,
        CLOSE_PARENTHESIS,

        NUMBER_CONSTANT,
        STRING_CONSTANT,
        IDENTIFIER,

        ENDLINE,
        SPACE,
        TAB,

        COMMA,
        SEMICOLON,
        UNDEFINED
    };

    explicit LasosToken(LasosType type, std::string_view value = "")
            : type(type), value(std::string(value)){};

    const LasosType type;
    const std::string value;
};

static const boost::regex IDENTIFIER_REGEX      ( R"([_]*[a-zA-Z][a-zA-Z0-9_]*)");
static const boost::regex STRING_CONSTANT_REGEX ( R"("(\\.|[^\\"])*")");
static const boost::regex NUMBER_CONSTANT_REGEX ( R"([+-]?\d+)");

static const std::map<std::string_view, LasosToken::LasosType> KEYWORDS = {
        {"for",    LasosToken::LasosType::FOR_KEYWORD},
        {"while",  LasosToken::LasosType::WHILE_KEYWORD},
        {"if",     LasosToken::LasosType::IF_KEYWORD},
        {"else",   LasosToken::LasosType::ELSE_KEYWORD},
        {"load",   LasosToken::LasosType::LOAD_KEYWORD},
        {"struct", LasosToken::LasosType::STRUCT_KEYWORD},
};

static const std::map<std::string_view, LasosToken::LasosType> OPERATORS = {
        {"+", LasosToken::LasosType::OPERATOR},
        {"-", LasosToken::LasosType::OPERATOR},
        {"*", LasosToken::LasosType::OPERATOR},
        {"/", LasosToken::LasosType::OPERATOR},
        {"%", LasosToken::LasosType::OPERATOR},
        {".", LasosToken::LasosType::OPERATOR},
};

static const std::map<std::string_view, LasosToken::LasosType> ASSIGN_OPERATOR = {
        {"=",  LasosToken::LasosType::ASSIGN_OPERATOR},
        {"+=", LasosToken::LasosType::ASSIGN_OPERATOR},
        {"-=", LasosToken::LasosType::ASSIGN_OPERATOR},
        {"*=", LasosToken::LasosType::ASSIGN_OPERATOR},
        {"/=", LasosToken::LasosType::ASSIGN_OPERATOR},
        {"%=", LasosToken::LasosType::ASSIGN_OPERATOR},
};

static const std::map<std::string_view, LasosToken::LasosType> BRACES = {
        {"(", LasosToken::LasosType::OPEN_PARENTHESIS},
        {")", LasosToken::LasosType::CLOSE_PARENTHESIS},
        {"{", LasosToken::LasosType::CURLY_OPEN_BRACE},
        {"}", LasosToken::LasosType::CURLY_CLOSE_BRACE},
        {":", LasosToken::LasosType::CURLY_CLOSE_BRACE},
};

static const std::map<std::string_view, LasosToken::LasosType> SEPARATORS = {
        {" ",  LasosToken::LasosType::SPACE},
        {"\t", LasosToken::LasosType::TAB},
        {"\n", LasosToken::LasosType::ENDLINE},
        {";",  LasosToken::LasosType::SEMICOLON},
        {",",  LasosToken::LasosType::COMMA},
};


bool is_keyword(const std::string_view& signature);
bool is_operator(const std::string_view& signature);
bool is_assign_operator(const std::string_view& signature);
bool is_brace(const std::string_view& signature);
bool is_separator(const std::string_view& signature);
bool is_identifier(const std::string_view& signature);
bool is_string_constant(const std::string_view& signature);


bool is_number_constant(const std::string_view& signature);


std::optional<LasosToken::LasosType> token_type_read(std::string_view signature);
std::optional<LasosToken> token_single_read(std::string_view& text);

std::vector<LasosToken> token_read(std::string_view text);


#endif
