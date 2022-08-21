#include "ReportCommand.h"
#include "../ToyRobot/ToyRobot.h"
#include <iostream>
#include <sstream>

namespace ToyRobot
{

ReportCommand::ReportCommand() :
    m_lastReport({})
{
}

bool ReportCommand::execute(ToyRobot *robot)
{
    if(!robot || !robot->isReady())
    {
        return false;
    }

    auto position = robot->getPosition();
    auto direction = robot->getDirection();

    m_lastReport = std::to_string(position.getX()) + "," + std::to_string(position.getY()) + "," + direction.toString();

    std::cout << m_lastReport << std::endl;

    return true;
}

std::string ReportCommand::getLastReport() const
{
    return m_lastReport;
}

}
