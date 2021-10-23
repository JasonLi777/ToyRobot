#include "ToyRobot.h"
#include "..\Command\AbstractCommand.h"

ToyRobot::ToyRobot() :
    m_status(ToyRobotStatus())
{
}

ToyRobot::~ToyRobot()
{
}

void ToyRobot::executeCommand(std::shared_ptr<AbstractCommand> command)
{
    if(command) {
        m_status = command->execute(m_status);
    }
}
