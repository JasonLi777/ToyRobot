#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "AbstractCommand.h"
#include "../Util/Direction.h"

namespace ToyRobot
{

class RotateCommand : public AbstractCommand
{
public:
    RotateCommand(const Direction::TurnEnum direction);
    virtual ~RotateCommand() = default;

    virtual bool execute(ToyRobot* robot) override;

    Direction::TurnEnum getDirection() const;

private:
    Direction::TurnEnum m_direction;
};

}

#endif // ROTATECOMMAND_H
