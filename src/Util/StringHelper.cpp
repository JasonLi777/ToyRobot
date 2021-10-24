#include "StringHelper.h"
#include <algorithm>

namespace StringHelper {

std::vector<std::string> split(const std::string &str, const std::string& sep)
{
    std::vector<std::string>  strings;

    if(str.empty() || sep.empty() || str == sep) {
        return strings;
    }

    std::size_t posFront = str.find_first_not_of(sep);
    std::size_t posAfter = str.find_first_of(sep, posFront);

    while(posFront != std::string::npos) {

        std::string subStr = str.substr(posFront, posAfter - posFront);
        strings.push_back(subStr);

        //if front cursor reach end then done
        if(posAfter == std::string::npos) {
            break;
        }

        posFront = str.find_first_not_of(sep, posAfter + sep.length());
        posAfter = str.find_first_of(sep, posFront);
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
