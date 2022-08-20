#include "CommandFactoryRegister.h"
#include "InputParser.h"

namespace ToyRobot
{

CommandFactoryRegister::CommandFactoryRegister(std::shared_ptr<AbstractCommandFactory> parser)
{
    InputParser::getInstance()->registerCommandFactory(std::move(parser));
}

}
