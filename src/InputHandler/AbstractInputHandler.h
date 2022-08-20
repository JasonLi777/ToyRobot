#ifndef ABSTRACTINPUTHANDLER_H
#define ABSTRACTINPUTHANDLER_H

#include <string>

namespace ToyRobot
{

class AbstractInputHandler
{
public:
    AbstractInputHandler() = default;
    virtual ~AbstractInputHandler() = default;

    virtual std::istream& getLine(std::string& output) = 0;
};

}

#endif // ABSTRACTINPUTHANDLER_H
