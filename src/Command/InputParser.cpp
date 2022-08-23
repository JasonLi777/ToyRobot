#include "InputParser.h"
#include "AbstractCommandFactory.h"
#include <iostream>

namespace ToyRobot
{

InputParser *InputParser::getInstance()
{
    static InputParser instance;
    return &instance;
}

std::shared_ptr<AbstractCommand> InputParser::parse(const std::string &input) const
{
    for(const auto& factory : m_parserContainer)
    {
        auto commandOpt = factory->build(input);

        if(commandOpt)
        {
            return commandOpt;
        }
    }

    return nullptr;
}

void InputParser::registerCommandFactory(std::shared_ptr<AbstractCommandFactory> parser)
{
    if(parser)
    {
        m_parserContainer.push_back(parser);
    }
}

}
