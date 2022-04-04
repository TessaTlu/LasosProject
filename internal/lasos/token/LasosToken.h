//
// Created by Расим Гаджиев on 26.03.2022.
//

#ifndef LASOSPROJECT_LASOSTOKEN_H
#define LASOSPROJECT_LASOSTOKEN_H
#include <string>

class LasosToken {
public:
    std::string type;
    std::string value;
    std::string to_string() const;
    LasosToken(std::string type, std::string value);
};


#endif //LASOSPROJECT_LASOSTOKEN_H
