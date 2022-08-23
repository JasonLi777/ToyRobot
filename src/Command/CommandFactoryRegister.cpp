#include "CommandFactoryRegister.h"
#include "CommandFactoryManager.h"

namespace ToyRobot
{

CommandFactoryRegister::CommandFactoryRegister(std::shared_ptr<AbstractCommandFactory> factory)
{
    CommandFactoryManager::getInstance()->registerCommandFactory(factory);
}

}
