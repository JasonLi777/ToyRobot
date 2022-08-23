#include "MoveCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "MoveCommand.h"

namespace ToyRobot
{

bool MoveCommandFactory::isMatched(const std::string& command) const
{
    return command == "MOVE";
}

std::shared_ptr<AbstractCommand> MoveCommandFactory::build(const std::string &command) const
{
    if(!isMatched(command))
    {
        return nullptr;
    }

    return std::make_shared<MoveCommand>();
}

REGISTER_COMMAND_FACTORY(MoveCommandFactory);

}
