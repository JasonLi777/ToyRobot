#include "Direction.h"

namespace ToyRobot
{

const std::vector<std::string> Direction::m_allDirection = {"NORTH", "EAST", "SOUTH", "WEST"};

Direction::Direction() :
    m_index(-1)
{
}

Direction::Direction(const std::string &direction) : Direction()
{
    auto itr = std::find(m_allDirection.cbegin(), m_allDirection.cend(), direction);
    m_index = (itr == m_allDirection.cend() ? -1 : std::distance(m_allDirection.cbegin(), itr));
}

bool Direction::operator==(const Direction &direction) const
{
    return m_index == direction.m_index;
}

std::string Direction::toString() const
{
    if(!isValid())
    {
        return {};
    }
    return m_allDirection[m_index];
}

bool Direction::isValid() const
{
    return m_index >= 0 && m_index < m_allDirection.size();
}

bool Direction::turn(const TurnEnum turn)
{
    if(!isValid())
    {
        return false;
    }

    m_index += (turn == LEFT ? -1 : 1);

    if(m_index == -1)
    {
        m_index = (m_allDirection.size() - 1);
    }

    if(m_index == m_allDirection.size())
    {
        m_index = 0;
    }

    return true;
}

}
