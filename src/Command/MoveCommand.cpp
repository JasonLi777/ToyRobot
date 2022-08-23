#include "MoveCommand.h"
#include "../ToyRobot/ToyRobot.h"

namespace ToyRobot
{

bool MoveCommand::execute(std::shared_ptr<ToyRobot> robot)
{
    if(!robot)
    {
        return false;
    }

    return robot->move();
}

}
