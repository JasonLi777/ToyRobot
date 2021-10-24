#include <iostream>
#include <string>
#include "ToyRobot\ToyRobot.h"
#include "TableTop\TableTop.h"
#include "ToyRobot\ToyRobotController.h"
#include "Util/StringHelper.h"
#include <fstream>

int main(int argc, char *argv[])
{
    try {
        std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
        std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
        std::shared_ptr<ToyRobotController> toyRobotController = std::make_shared<ToyRobotController>(toyRobot, tableTop);

        std::cout << "Command:" << std::endl;
        std::cout << "   PLACE X,Y,F" << std::endl;
        std::cout << "   MOVE" << std::endl;
        std::cout << "   LEFT" << std::endl;
        std::cout << "   RIGHT" << std::endl;
        std::cout << "   REPORT" << std::endl;
        std::cout << "Please enter the above commands to control the toy robot, enter 'QUIT' to exit." << std::endl << std::endl;

        //use input
        if(argc == 1) {

            //start receive command from user and use controller to control toy robot
            while (true) {
                std::string command;
                std::getline(std::cin, command);

                if(StringHelper::toUpper(command) == "QUIT") {
                    break;
                }

                toyRobotController->execute(command);
            }
        }
        //read from file
        else if(argc == 2) {

            std::ifstream infile(argv[1]);
            if (infile.is_open()) {

                std::string command;
                while (std::getline(infile, command)) {
                    toyRobotController->execute(command);
                }

                infile.close();
            }

        } else {
            return 1;
        }

    }  catch (...) {
        std::cout << "Something wrong happened!" << std::endl;
        return 1;
    }

    return 0;
}
