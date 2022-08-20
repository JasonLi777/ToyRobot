#include "ToyRobot.h"
#include "../TableTop/TableTop.h"
#include "..\Command\AbstractCommand.h"

ToyRobot::ToyRobot(const std::shared_ptr<TableTop> &tableTop) :
    m_tableTop(std::move(tableTop)),
    m_position(Position()),
    m_direction(Direction()),
    m_ready(false)
{
}

bool ToyRobot::executeCommand(const std::shared_ptr<AbstractCommand> &command)
{
    if(!command)
    {
        return false;
    }

    return command->execute(this);
}

bool ToyRobot::place(const Position &position, const Direction &direction)
{
    if(!m_tableTop || !(position.isValid() && direction.isValid()) || !m_tableTop->isOnTheTable(position))
    {
        return false;
    }

    m_position = position;
    m_direction = direction;
    m_ready = true;

    return true;
}

bool ToyRobot::setPosition(const Position &position)
{
    if(!m_ready || !m_tableTop->isOnTheTable(position))
    {
        return false;
    }

    m_position = position;

    return true;
}

Position ToyRobot::getPosition() const
{
    return m_position;
}

bool ToyRobot::setDirection(const Direction &direction)
{
    if(!m_ready)
    {
        return false;
    }

    m_direction = direction;

    return true;
}

Direction ToyRobot::getDirection() const
{
    return m_direction;
}

bool ToyRobot::isReady() const
{
    return m_ready;
}
