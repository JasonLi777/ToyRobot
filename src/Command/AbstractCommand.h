#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <memory>

namespace ToyRobot
{

class ToyRobot;

class AbstractCommand
{
public:
    AbstractCommand() = default;
    virtual ~AbstractCommand() = default;

    virtual bool execute(std::shared_ptr<ToyRobot> robot) = 0;
};

}

#endif // ABSTRACTCOMMAND_H
