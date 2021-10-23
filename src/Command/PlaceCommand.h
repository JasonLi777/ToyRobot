#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include <memory>
#include "AbstractCommand.h"
#include "..\Util\Position.h"
#include "..\Util\Direction.h"

class TableTop;

class PlaceCommand : public AbstractCommand
{
public:
    PlaceCommand(std::shared_ptr<TableTop> tableTop,
                 const Position& position,
                 const Direction& direction);
    virtual ~PlaceCommand();

    virtual ToyRobotStatus execute(const ToyRobotStatus& oldStatus) override;

private:
    std::shared_ptr<TableTop> m_tableTop;
    Position m_position;
    Direction m_direction;
};

#endif // PLACECOMMAND_H
