#ifndef STRINGHELPER_H
#define STRINGHELPER_H

#include <vector>
#include <string>

namespace StringHelper {

std::vector<std::string> split(const std::string& str, const std::string& sep);
std::string toUpper(const std::string& str);

}

#endif // STRINGHELPER_H
