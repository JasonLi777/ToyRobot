#include <iostream>
#include <string>
#include "ToyRobot\ToyRobot.h"
#include "TableTop\TableTop.h"
#include "ToyRobot\ToyRobotController.h"

int main()
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    std::shared_ptr<ToyRobotController> toyRobotController = std::make_shared<ToyRobotController>(toyRobot, tableTop);

    std::cout << "Command:" << std::endl;
    std::cout << "   PLACE X,Y,F" << std::endl;
    std::cout << "   MOVE" << std::endl;
    std::cout << "   LEFT" << std::endl;
    std::cout << "   RIGHT" << std::endl;
    std::cout << "   REPORT" << std::endl;
    std::cout << "Please enter the above commands to control the toy robot." << std::endl;

    //start receive command from user and use controller to control toy robot
    while (true) {
        std::string command;
        std::getline(std::cin, command);

        if(command == "QUIT") {
            break;
        }

        toyRobotController->execute(command);
    }

    return 0;
}
