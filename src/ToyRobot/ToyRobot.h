#ifndef TOYROBOT_H
#define TOYROBOT_H

#include <memory>
#include "ToyRobotStatus.h"

class AbstractCommand;

class ToyRobot
{
public:
    ToyRobot();
    ~ToyRobot();

    //execute command and update status
    void executeCommand(std::shared_ptr<AbstractCommand> command);

private:
    ToyRobotStatus m_status;
};

#endif // TOYROBOT_H
