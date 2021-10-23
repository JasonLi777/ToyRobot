#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "AbstractCommand.h"
#include "..\Util\Direction.h"

class RotateCommand : public AbstractCommand
{
public:
    RotateCommand(const Direction::TurnEnum direction);
    virtual ~RotateCommand();

    virtual ToyRobotStatus execute(const ToyRobotStatus& oldStatus) override;

private:
    Direction::TurnEnum m_direction;
};

#endif // ROTATECOMMAND_H
