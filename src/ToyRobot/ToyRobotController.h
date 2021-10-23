#ifndef TOYROBOTCONTROLLER_H
#define TOYROBOTCONTROLLER_H

#include <memory>
#include <string>

class ToyRobot;
class TableTop;
class AbstractCommand;

class ToyRobotController
{
public:
    ToyRobotController(std::shared_ptr<ToyRobot> toyRobot, std::shared_ptr<TableTop> tableTop = nullptr);
    ~ToyRobotController();

    bool execute(const std::string& command);

protected:
    std::shared_ptr<AbstractCommand> parseCommand(const std::string& command) const;


private:
    std::shared_ptr<ToyRobot> m_toyRobot;
    std::shared_ptr<TableTop> m_tableTop;
};

#endif // TOYROBOTCONTROLLER_H
