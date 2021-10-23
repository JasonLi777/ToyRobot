#include "ReportCommand.h"
#include "..\ToyRobot\ToyRobotStatus.h"
#include <iostream>

ReportCommand::ReportCommand()
{
}

ReportCommand::~ReportCommand()
{
}

ToyRobotStatus ReportCommand::execute(const ToyRobotStatus& oldStatus)
{
    //if old status is invalid, means toy robot or table not init properly or robot is not on the table
    //so do nothing just return old status
    if(!oldStatus.isValid()) {
        return oldStatus;
    }

    Position position = oldStatus.position();

    std::cout << position.x() << "," << position.y() << "," << oldStatus.direction().toString() << std::endl;

    return oldStatus;
}
