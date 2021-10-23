#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "AbstractCommand.h"

class MoveCommand : public AbstractCommand
{
public:
    MoveCommand();
    virtual ~MoveCommand();

    virtual ToyRobotStatus execute(const ToyRobotStatus& oldStatus) override;

private:
    int m_step;
};

#endif // MOVECOMMAND_H
