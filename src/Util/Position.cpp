#include "Position.h"

Position::Position():
    Position(-1, -1)
{
}

Position::Position(const int x, const int y) :
    m_x(x),
    m_y(y)
{
}

bool Position::operator==(const Position &position) const
{
    return m_x == position.getX() && m_y == position.getY();
}

int Position::getX() const
{
    return m_x;
}

void Position::setX(const int x)
{
    m_x = x;
}

int Position::getY() const
{
    return m_y;
}

void Position::setY(const int y)
{
    m_y = y;
}

bool Position::isValid() const
{
    return m_x >= 0 && m_y >= 0;
}

