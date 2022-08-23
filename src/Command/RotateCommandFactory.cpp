#include "RotateCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "RotateCommand.h"

namespace ToyRobot
{

bool RotateCommandFactory::isMatched(const std::string& command) const
{
    return command == "LEFT" || command == "RIGHT";
}

std::shared_ptr<AbstractCommand> RotateCommandFactory::build(const std::string &command) const
{
    if(!isMatched(command))
    {
        return nullptr;
    }

    return std::make_shared<RotateCommand>(command == "LEFT" ? Direction::TurnDirection::LEFT : Direction::TurnDirection::RIGHT);
}

REGISTER_COMMAND_FACTORY(RotateCommandFactory);

}
