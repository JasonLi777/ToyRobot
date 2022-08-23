#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "AbstractCommand.h"

namespace ToyRobot
{

class Position;

class MoveCommand : public AbstractCommand
{
public:
    MoveCommand() = default;
    virtual ~MoveCommand() = default;

    virtual bool execute(std::shared_ptr<ToyRobot> robot) override;
};

}

#endif // MOVECOMMAND_H
