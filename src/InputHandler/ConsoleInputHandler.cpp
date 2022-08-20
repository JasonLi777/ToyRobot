#include "ConsoleInputHandler.h"
#include <iostream>

namespace ToyRobot
{

std::istream& ConsoleInputHandler::getLine(std::string& output)
{
    return std::getline(std::cin, output);
}

}
