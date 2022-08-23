#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "AbstractCommand.h"
#include "../Util/Direction.h"

namespace ToyRobot
{

class RotateCommand : public AbstractCommand
{
public:
    RotateCommand(const Direction::TurnDirection direction);
    virtual ~RotateCommand() = default;

    virtual bool execute(std::shared_ptr<ToyRobot> robot) override;

    Direction::TurnDirection getDirection() const;

private:
    Direction::TurnDirection m_direction;
};

}

#endif // ROTATECOMMAND_H
