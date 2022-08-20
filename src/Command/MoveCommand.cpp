#include "MoveCommand.h"
#include "../ToyRobot/ToyRobot.h"

bool MoveCommand::execute(ToyRobot *robot)
{
    if(!robot || !robot->isReady())
    {
        return false;
    }

    auto position = robot->getPosition();

    switch (robot->getDirection().value())
    {
    case Direction::NORTH:
    {
        position.setY(position.getY() + 1);
        break;
    }
    case Direction::WEST:
    {
        position.setX(position.getX() - 1);
        break;
    }
    case Direction::SOUTH:
    {
        position.setY(position.getY() - 1);
        break;
    }
    case Direction::EAST:
    {
        position.setX(position.getX() + 1);
        break;
    }
    default:
    {
        break;
    }
    }

    return robot->setPosition(position);
}
