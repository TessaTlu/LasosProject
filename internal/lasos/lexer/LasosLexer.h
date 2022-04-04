#ifndef LASOSPROJECT_LASOSLEXER_H
#define LASOSPROJECT_LASOSLEXER_H

#include <string>
#include <vector>
#include <map>
#include "../token/LasosToken.h"

class LasosLexer {
private:
    std::vector<std::string> functions = {"+", "-", "*", "/"};
    std::vector<std::string> sign_of = {"="};
    std::vector<std::string> comparator_operations = {"==", "<", ">", "<=", ">="};
    std::vector<std::string> single_char_keywords = {"{", "}", "\"", "'", "(", ")"};
    std::map<std::string, std::vector<std::string>> types;

    void map_characters();

    std::string match_character(std::string *word);

public:
    LasosLexer();

    std::vector<LasosToken> read(std::string *input);
};


#endif
