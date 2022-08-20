#ifndef CONSOLEINPUTHANDLER_H
#define CONSOLEINPUTHANDLER_H

#include "AbstractInputHandler.h"

namespace ToyRobot
{

class ConsoleInputHandler : public AbstractInputHandler
{
public:
    ConsoleInputHandler() = default;
    virtual ~ConsoleInputHandler() = default;

    virtual std::istream& getLine(std::string& output) override;
};

}

#endif // CONSOLEINPUTHANDLER_H
