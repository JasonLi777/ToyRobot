#include "TableTop.h"
#include "..\Util\Position.h"

TableTop::TableTop(const int width, const int length):
    m_width(width),
    m_length(length)
{
}

TableTop::~TableTop()
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
    return position.x() >= 0 && position.x() < m_width && position.y() >= 0 && position.y() < m_length;
}

