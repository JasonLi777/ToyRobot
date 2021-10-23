#include "StringHelper.h"

namespace StringHelper {

std::vector<std::string> split(const std::string &str, const std::string& sep)
{
    std::vector<std::string>  strings;

    if(str.empty() || sep.empty()) {
        return strings;
    }

    std::size_t posFront = 0;
    std::size_t posAfter = str.find(sep);

    while(posAfter != std::string::npos) {
        std::string subStr = str.substr(posFront, posAfter - posFront);
        strings.push_back(subStr);

        posFront = posAfter + sep.length();
        posAfter = str.find(sep, posFront);
    }

    if(posFront != str.length()) {
        strings.push_back(str.substr(posFront));
    }

    return strings;
}

}
