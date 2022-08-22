#include "TableTop.h"
#include "../Util/Position.h"

namespace ToyRobot
{

TableTop::TableTop(const int width, const int length) :
    m_width(width),
    m_length(length)
{
}

int TableTop::getWidth() const
{
    return m_width;
}

int TableTop::getLength() const
{
    return m_length;
}

bool TableTop::isValid() const
{
    return m_width > 0 && m_length > 0;
}

bool TableTop::isOnTheTable(const Position &position) const
{
    if(!isValid())
    {
        return false;
    }

    return position.getX() >= 0 && position.getX() < m_width && position.getY() >= 0 && position.getY() < m_length;
}

}

