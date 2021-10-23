#include "ToyRobotStatus.h"
#include "..\TableTop\TableTop.h"

ToyRobotStatus::ToyRobotStatus() :
    m_tableTop(nullptr),
    m_position(Position()),
    m_direction(Direction())
{
}

ToyRobotStatus::~ToyRobotStatus()
{
}

std::shared_ptr<TableTop> ToyRobotStatus::tableTop() const
{
    return m_tableTop;
}

void ToyRobotStatus::setTableTop(std::shared_ptr<TableTop> tableTop)
{
    m_tableTop = tableTop;
}

Position ToyRobotStatus::position() const
{
    return m_position;
}

void ToyRobotStatus::setPosition(const Position &position)
{
    m_position = position;
}

Direction ToyRobotStatus::direction() const
{
    return m_direction;
}

void ToyRobotStatus::setDirection(const Direction &direction)
{
    m_direction = direction;
}

bool ToyRobotStatus::isValid() const
{
    if(!m_tableTop) {
        return false;
    }

    bool isAllValid = m_tableTop->isValid() && m_position.isValid() && m_direction.isValid();

    //if value are valid then check if position on the table
    if(isAllValid) {
        return m_tableTop->isOnTheTable(m_position);
    }

    return isAllValid;
}
