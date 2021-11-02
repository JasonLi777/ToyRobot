#include "StringHelper.h"
#include <algorithm>

namespace StringHelper {

std::vector<std::string> split(const std::string &str, const std::string& sep)
{
    std::vector<std::string>  strings;

    if(str.empty() || sep.empty() || str == sep) {
        return strings;
    }

    std::size_t posFront = 0;
    std::size_t posAfter = str.find(sep, posFront);

    while(posFront != std::string::npos) {

        if (posFront == posAfter) {
            posFront = posAfter + sep.length();
            posAfter = str.find(sep, posFront);

            if (posAfter == std::string::npos) {
                break;
            }

            continue;
        }

        std::string subStr = str.substr(posFront, posAfter - posFront);
        strings.push_back(subStr);

        //if front cursor reach end then done
        if(posAfter == std::string::npos) {
            break;
        }

        posFront = posAfter + sep.length();
        posAfter = str.find(sep, posFront);
    }

    return strings;
}

std::string toUpper(const std::string &str)
{
    std::string _str = str;
    std::for_each(_str.begin(), _str.end(), [](char& c){
        c = ::toupper(c);
    });
    return _str;
}



}
