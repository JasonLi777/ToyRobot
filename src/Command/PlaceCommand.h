#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include <memory>
#include "AbstractCommand.h"
#include "../Util/Position.h"
#include "../Util/Direction.h"

namespace ToyRobot
{

class TableTop;

class PlaceCommand : public AbstractCommand
{
public:
    PlaceCommand(const Position& position, const Direction& direction);
    virtual ~PlaceCommand() = default;

    virtual bool execute(std::shared_ptr<ToyRobot> robot) override;

private:
    Position m_position;
    Direction m_direction;
};

}

#endif // PLACECOMMAND_H
