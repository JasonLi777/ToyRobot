#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

class ToyRobot;
class ToyRobotStatus;

class AbstractCommand
{
public:
    AbstractCommand();
    virtual ~AbstractCommand();

    //input old status, then execute and return new status
    virtual ToyRobotStatus execute(const ToyRobotStatus& oldStatus) = 0;
};

#endif // ABSTRACTCOMMAND_H
