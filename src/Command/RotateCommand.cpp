#include "RotateCommand.h"
#include "../ToyRobot/ToyRobot.h"

namespace ToyRobot
{

RotateCommand::RotateCommand(const Direction::TurnEnum direction) :
    m_direction(direction)
{
}


bool RotateCommand::execute(ToyRobot *robot)
{
    if(!robot || !robot->isReady())
    {
        return false;
    }

    auto direction = robot->getDirection();
    direction.turn(m_direction);

    return robot->setDirection(direction);
}

}
