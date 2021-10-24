#include "ReportCommand.h"
#include "..\ToyRobot\ToyRobotStatus.h"
#include <iostream>
#include <sstream>

ReportCommand::ReportCommand() :
    m_lastReport("")
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

    std::ostringstream stream;
    stream << position.x() << "," << position.y() << "," << oldStatus.direction().toString();

    //keep current report
    m_lastReport = stream.str();

    std::cout << m_lastReport << std::endl;

    return oldStatus;
}

std::string ReportCommand::getLastReport() const
{
    return m_lastReport;
}
