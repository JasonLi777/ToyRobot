#include "MoveCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "MoveCommand.h"

std::optional<std::shared_ptr<AbstractCommand> > MoveCommandFactory::build(const std::string &command) const
{
    if(command == "MOVE")
    {
        return std::make_shared<MoveCommand>();
    }

    return {};
}

REGISTER_COMMAND_FACTORY(MoveCommandFactory);
