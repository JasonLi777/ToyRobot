#include "PlaceCommand.h"
#include "..\ToyRobot\ToyRobotStatus.h"

PlaceCommand::PlaceCommand(std::shared_ptr<TableTop> tableTop,
                           const Position &position,
                           const Direction &direction) :
    m_tableTop(tableTop),
    m_position(position),
    m_direction(direction)
{
}

PlaceCommand::~PlaceCommand()
{
}

ToyRobotStatus PlaceCommand::execute(const ToyRobotStatus& oldStatus)
{
    ToyRobotStatus newStatus = ToyRobotStatus();
    newStatus.setTableTop(m_tableTop);
    newStatus.setPosition(m_position);
    newStatus.setDirection(m_direction);

    //if new status valid(also new position on the table) then use new status
    if(newStatus.isValid()) {
        return newStatus;
    }

    //if new status is not valid then use old status
    return oldStatus;
}
