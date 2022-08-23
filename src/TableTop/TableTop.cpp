#include "TableTop.h"

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

bool TableTop::isOnTheTable(const int x, const int y) const
{
    if(!isValid())
    {
        return false;
    }

    return x >= 0 && x < m_width && y >= 0 && y < m_length;
}

}

