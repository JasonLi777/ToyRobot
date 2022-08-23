#include "ReportCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "ReportCommand.h"

namespace ToyRobot
{

bool ReportCommandFactory::isMatched(const std::string& command) const
{
    return command == "REPORT";
}

std::shared_ptr<AbstractCommand> ReportCommandFactory::build(const std::string &command) const
{
    if(!isMatched(command))
    {
        return nullptr;
    }

    return std::make_shared<ReportCommand>();
}

REGISTER_COMMAND_FACTORY(ReportCommandFactory);

}
