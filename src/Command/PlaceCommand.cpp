#include "PlaceCommand.h"
#include "../ToyRobot/ToyRobot.h"

namespace ToyRobot
{

PlaceCommand::PlaceCommand(const Position &position, const Direction &direction)
    : m_position(position), m_direction(direction)
{
}

bool PlaceCommand::execute(ToyRobot *robot)
{
    if(!robot)
    {
        return false;
    }

    return robot->place(m_position, m_direction);
}

}
