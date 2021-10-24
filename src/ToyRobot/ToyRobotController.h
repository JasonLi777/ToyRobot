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

    //execute command
    bool execute(const std::string& command);

    //parse input and return command obj, if invalid then return nullptr
    std::shared_ptr<AbstractCommand> parseCommand(const std::string& command) const;

    std::shared_ptr<ToyRobot> toyRobot() const;
    std::shared_ptr<TableTop> tableTop() const;

private:
    std::shared_ptr<ToyRobot> m_toyRobot;
    std::shared_ptr<TableTop> m_tableTop;
};

#endif // TOYROBOTCONTROLLER_H
