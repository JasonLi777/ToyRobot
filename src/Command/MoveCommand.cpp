#include "MoveCommand.h"
#include "..\ToyRobot\ToyRobotStatus.h"

MoveCommand::MoveCommand() :
    //default 1 step, maybe can move multiple step later
    m_step(1)
{
}

MoveCommand::~MoveCommand()
{
}

ToyRobotStatus MoveCommand::execute(const ToyRobotStatus& oldStatus)
{
    //if old status is invalid, means toy robot or table not init properly or robot is not on the table
    //so do nothing just return old status
    if(m_step <= 0 || !oldStatus.isValid()) {
        return oldStatus;
    }

    Position newPosition = oldStatus.position();

    //calculate new position by direction
    switch (oldStatus.direction().value()) {
    case Direction::NORTH: {
        newPosition.setY(newPosition.y() + m_step);
        break;
    }
    case Direction::WEST: {
        newPosition.setX(newPosition.x() - m_step);
        break;
    }
    case Direction::SOUTH: {
        newPosition.setY(newPosition.y() - m_step);
        break;
    }
    case Direction::EAST: {
        newPosition.setX(newPosition.x() + m_step);
        break;
    }
    default: {
        break;
    }
    }

    ToyRobotStatus newStatus = oldStatus;
    newStatus.setPosition(newPosition);

    //verify new status, include whether new status positon on table top
    //if is not valid, just ignor this command and use old status
    if(!newStatus.isValid()) {
        return oldStatus;
    }

    return newStatus;
}
