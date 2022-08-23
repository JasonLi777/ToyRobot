#include "RotateCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "RotateCommand.h"

namespace ToyRobot
{

std::shared_ptr<AbstractCommand> RotateCommandFactory::build(const std::string &command) const
{
    if(command == "LEFT")
    {
        return std::make_shared<RotateCommand>(Direction::TurnDirection::LEFT);
    }
    else if(command == "RIGHT")
    {
        return std::make_shared<RotateCommand>(Direction::TurnDirection::RIGHT);
    }
    else
    {
        return nullptr;
    }
}

REGISTER_COMMAND_FACTORY(RotateCommandFactory);

}
