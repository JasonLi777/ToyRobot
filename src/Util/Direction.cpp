#include "Direction.h"

Direction Direction::fromString(const std::string &direction)
{
    if(direction == "NORTH")
    {
        return Direction(NORTH);
    }
    else if(direction == "WEST")
    {
        return Direction(WEST);
    }
    else if(direction == "SOUTH")
    {
        return Direction(SOUTH);
    }
    else if(direction == "EAST")
    {
        return Direction(EAST);
    }
    else
    {
        return Direction();
    }
}

Direction::Direction() : Direction(INVALID)
{
}

Direction::Direction(const Direction::DirectionEnum direction) :
    m_direction(direction)
{

}

bool Direction::operator==(const Direction &direction) const
{
    return m_direction == direction.value();
}

Direction::DirectionEnum Direction::value() const
{
    return m_direction;
}

void Direction::setValue(const DirectionEnum dir)
{
    m_direction = dir;
}

std::string Direction::toString() const
{
    switch (m_direction)
    {
    case NORTH:
    {
        return "NORTH";
    }
    case WEST:
    {
        return "WEST";
    }
    case SOUTH:
    {
        return "SOUTH";
    }
    case EAST:
    {
        return "EAST";
    }
    default:
    {
        return "INVALID";
    }
    }
}

bool Direction::isValid() const
{
    return m_direction != INVALID;
}

bool Direction::turn(const TurnEnum turn)
{
    if(!isValid())
    {
        return false;
    }

    switch (m_direction)
    {
    case NORTH:
    {
        m_direction = (turn == LEFT ? WEST : EAST);
        break;
    }
    case WEST:
    {
        m_direction = (turn == LEFT ? SOUTH : NORTH);
        break;
    }
    case SOUTH:
    {
        m_direction = (turn == LEFT ? EAST : WEST);
        break;
    }
    case EAST:
    {
        m_direction = (turn == LEFT ? NORTH : SOUTH);
        break;
    }
    default:
    {
        return false;
    }
    }

    return true;
}
