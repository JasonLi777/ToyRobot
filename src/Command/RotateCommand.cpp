#include "RotateCommand.h"
#include "..\ToyRobot\ToyRobotStatus.h"

RotateCommand::RotateCommand(const Direction::TurnEnum direction) :
    m_direction(direction)
{
}

RotateCommand::~RotateCommand()
{
}

ToyRobotStatus RotateCommand::execute(const ToyRobotStatus& oldStatus)
{
    //if old status is invalid, means toy robot or table not init properly or robot is not on the table
    //so do nothing just return old status
    if(!oldStatus.isValid()) {
        return oldStatus;
    }

    //turn direction and get new direction
    Direction newDirection = oldStatus.direction();
    if(!newDirection.turn(m_direction)) {
        return oldStatus;
    }

    //update new direction to old status
    ToyRobotStatus newStatus = oldStatus;
    newStatus.setDirection(newDirection);

    return newStatus;
}
