#include "CommandFactoryManager.h"
#include "AbstractCommandFactory.h"
#include <iostream>

namespace ToyRobot
{

CommandFactoryManager *CommandFactoryManager::getInstance()
{
    static CommandFactoryManager instance;
    return &instance;
}

std::shared_ptr<AbstractCommandFactory> CommandFactoryManager::findFactory(const std::string &input) const
{
    for(const auto& factory : m_allFactory)
    {
        if(factory->isMatched(input))
        {
            return factory;
        }
    }

    return nullptr;
}

void CommandFactoryManager::registerCommandFactory(std::shared_ptr<AbstractCommandFactory> factory)
{
    if(factory)
    {
        m_allFactory.push_back(factory);
    }
}

}
