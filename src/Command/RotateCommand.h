#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "AbstractCommand.h"
#include "../ToyRobot/Direction.h"

namespace ToyRobot
{

class RotateCommand : public AbstractCommand
{
public:
    RotateCommand(const Direction::TurnDirection turnDirection);
    virtual ~RotateCommand() = default;

    virtual bool execute(std::shared_ptr<ToyRobot> robot) override;

    Direction::TurnDirection getDirection() const;

private:
    Direction::TurnDirection m_turnDirection;
};

}

#endif // ROTATECOMMAND_H
