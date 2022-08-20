#include "RotateCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "RotateCommand.h"

std::optional<std::shared_ptr<AbstractCommand> > RotateCommandFactory::build(const std::string &command) const
{
    if(command == "LEFT")
    {
        return std::make_shared<RotateCommand>(Direction::LEFT);
    }
    else if (command == "RIGHT")
    {
        return std::make_shared<RotateCommand>(Direction::RIGHT);
    }
    else
    {
        return {};
    }
}

REGISTER_COMMAND_FACTORY(RotateCommandFactory);
