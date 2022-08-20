#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "AbstractCommand.h"

class MoveCommand : public AbstractCommand
{
public:
    MoveCommand() = default;
    virtual ~MoveCommand() = default;

    virtual bool execute(ToyRobot* robot) override;
};

#endif // MOVECOMMAND_H
