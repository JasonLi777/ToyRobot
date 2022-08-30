#include "ToyRobot.h"
#include "../TableTop/TableTop.h"

namespace ToyRobot
{

const std::unordered_map<std::string, std::function<void(Position& position)>> ToyRobot::m_moveFuncMap =
{
    {
        "NORTH",
        [](Position& position) { position.setY(position.getY() + 1); }
    },
    {
        "WEST",
        [](Position& position) { position.setX(position.getX() - 1); }
    },
    {
        "SOUTH",
        [](Position& position) { position.setY(position.getY() - 1); }
    },
    {
        "EAST",
        [](Position& position) { position.setX(position.getX() + 1); }
    },
};

ToyRobot::ToyRobot(std::shared_ptr<TableTop> tableTop) :
    m_tableTop(tableTop),
    m_position(Position()),
    m_direction(Direction()),
    m_placed(false)
{
}

bool ToyRobot::place(const Position &position, const Direction &direction)
{
    if(!m_tableTop || !(position.isValid() && direction.isValid()) || !m_tableTop->isOnTheTable(position.getX(), position.getY()))
    {
        return false;
    }

    m_position = position;
    m_direction = direction;
    m_placed = true;

    return true;
}

bool ToyRobot::move()
{
    if(!isPlaced())
    {
        return false;
    }

    auto itr = m_moveFuncMap.find(m_direction.toString());
    if(itr == m_moveFuncMap.end())
    {
        return false;
    }

    auto newPosition = m_position;
    itr->second(newPosition);

    if(!m_tableTop->isOnTheTable(newPosition.getX(), newPosition.getY()))
    {
        return false;
    }
    m_position = newPosition;

    return true;
}

bool ToyRobot::rotate(const Direction::TurnDirection turnDirection)
{
    if(!isPlaced())
    {
        return false;
    }

    m_direction.turn(turnDirection);
    return true;
}

Position ToyRobot::getPosition() const
{
    return m_position;
}

Direction ToyRobot::getDirection() const
{
    return m_direction;
}

bool ToyRobot::isPlaced() const
{
    return m_placed;
}

}
