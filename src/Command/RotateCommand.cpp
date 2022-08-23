#include "RotateCommand.h"
#include "../ToyRobot/ToyRobot.h"

namespace ToyRobot
{

RotateCommand::RotateCommand(const Direction::TurnDirection turnDirection) :
    m_turnDirection(turnDirection)
{
}


bool RotateCommand::execute(std::shared_ptr<ToyRobot> robot)
{
    if(!robot)
    {
        return false;
    }

    return robot->rotate(m_turnDirection);
}

}
