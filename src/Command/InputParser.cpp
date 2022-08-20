#include "InputParser.h"
#include "AbstractCommandFactory.h"
#include <iostream>

InputParser *InputParser::getInstance()
{
    static InputParser instance;
    return &instance;
}

std::optional<std::shared_ptr<AbstractCommand> > InputParser::parse(const std::string &input) const
{
    for(const auto& factory : m_parserContainer)
    {
        if(!factory)
        {
            continue;
        }

        auto commandOpt = factory->build(input);

        if(commandOpt)
        {
            return commandOpt;
        }
    }

    std::cout << "Invalid input!" << std::endl;

    return {};
}

void InputParser::registerCommandFactory(std::shared_ptr<AbstractCommandFactory> parser)
{
    if(parser)
    {
        m_parserContainer.push_back(parser);
    }
}

