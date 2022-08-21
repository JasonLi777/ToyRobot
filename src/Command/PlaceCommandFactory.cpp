#include "PlaceCommandFactory.h"
#include "CommandFactoryRegister.h"
#include "PlaceCommand.h"
#include "../Util/Direction.h"
#include "../Util/Position.h"
#include <regex>

namespace ToyRobot
{

std::optional<std::shared_ptr<AbstractCommand> > PlaceCommandFactory::build(const std::string &command) const
{
    std::smatch matchResult;

    bool isMatched = std::regex_match(command, matchResult, std::regex("PLACE ([0-4]),([0-4]),(NORTH|WEST|SOUTH|EAST)"));

    if(!isMatched || matchResult.size() != 4)
    {
        return {};
    }

    auto position = Position(std::stoi(matchResult[1].str()), std::stoi(matchResult[2].str()));
    auto direction = Direction(matchResult[3].str());

    return std::make_shared<PlaceCommand>(position, direction);
}

REGISTER_COMMAND_FACTORY(PlaceCommandFactory);

}
