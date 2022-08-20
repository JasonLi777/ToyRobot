#include "ReportCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "ReportCommand.h"

std::optional<std::shared_ptr<AbstractCommand> > ReportCommandFactory::build(const std::string &command) const
{
    if(command == "REPORT")
    {
        return std::make_shared<ReportCommand>();
    }
    return {};
}

REGISTER_COMMAND_FACTORY(ReportCommandFactory);
