#include "ToyRobotController.h"
#include "ToyRobot.h"
#include "..\TableTop\TableTop.h"
#include "..\Command\AbstractCommand.h"
#include "..\Command\MoveCommand.h"
#include "..\Command\PlaceCommand.h"
#include "..\Command\ReportCommand.h"
#include "..\Command\RotateCommand.h"
#include "..\Util\StringHelper.h"
#include <memory>

#include <iostream>

ToyRobotController::ToyRobotController(std::shared_ptr<ToyRobot> toyRobot, std::shared_ptr<TableTop> tableTop) :
    m_toyRobot(toyRobot),
    m_tableTop(tableTop)
{
}

ToyRobotController::~ToyRobotController()
{
}

bool ToyRobotController::execute(const std::string &command)
{
    if(!m_toyRobot || !m_tableTop) {
        return false;
    }

    //parse command and get toy command obj
    std::shared_ptr<AbstractCommand> commandObj = parseCommand(command);
    if(!commandObj) {
        std::cout << "Invalid input!" << std::endl;
        return false;
    }

    //toy robot execute command
    m_toyRobot->executeCommand(commandObj);

    return true;
}

std::shared_ptr<AbstractCommand> ToyRobotController::parseCommand(const std::string &command) const
{
    std::vector<std::string> subs = StringHelper::split(command, " ");
    if(subs.empty()) {
        return nullptr;
    }

    std::string action = subs[0];

    if(action == "PLACE") {
        //first string is action, second string is parameters
        if(subs.size() != 2) {
            return nullptr;
        }

        //split second string to get parameters
        std::vector<std::string> parameters = StringHelper::split(subs[1], ",");
        if(parameters.size() != 3) {
            return nullptr;
        }

        try {
            Position position = Position(std::stoi(parameters[0]), std::stoi(parameters[1]));
            Direction direction = Direction::fromString(parameters[2]);
            if(!position.isValid() || !direction.isValid()) {
                return nullptr;
            }

            return std::make_shared<PlaceCommand>(m_tableTop, position, direction);
        }  catch (std::exception e) {
            return nullptr;
        }
    } else if(action == "MOVE") {
        return std::make_shared<MoveCommand>();
    } else if(action == "LEFT") {
        return std::make_shared<RotateCommand>(Direction::LEFT);
    } else if(action == "RIGHT") {
        return std::make_shared<RotateCommand>(Direction::RIGHT);
    } else if(action == "REPORT") {
        return std::make_shared<ReportCommand>();
    }

    return nullptr;
}

