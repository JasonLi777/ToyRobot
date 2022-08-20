#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

namespace ToyRobot
{

class ToyRobot;

class AbstractCommand
{
public:
    AbstractCommand() = default;
    virtual ~AbstractCommand() = default;

    virtual bool execute(ToyRobot* robot) = 0;
};

}

#endif // ABSTRACTCOMMAND_H
