#include <iostream>
#include <string>
#include "ToyRobot\ToyRobot.h"
#include "TableTop\TableTop.h"
#include <fstream>
#include "Command/InputParser.h"

//void processArc(arc, argv)

int main(int argc, char *argv[])
{
    try {
        std::shared_ptr<ToyRobot::TableTop> tableTop = std::make_shared<ToyRobot::TableTop>(5, 5);
        std::shared_ptr<ToyRobot::ToyRobot> toyRobot = std::make_shared<ToyRobot::ToyRobot>(tableTop);

        std::cout << "Command:" << std::endl;
        std::cout << "   PLACE X,Y,F" << std::endl;
        std::cout << "   MOVE" << std::endl;
        std::cout << "   LEFT" << std::endl;
        std::cout << "   RIGHT" << std::endl;
        std::cout << "   REPORT" << std::endl;
        std::cout << "Please enter the above commands to control the toy robot." << std::endl << std::endl;

        //make it expandable
        // class AbstractInput { std::istream getInputStream() }
        // class ConsoleInput {  std::istream getInputStream() { return std::cin } }
        // class FileInput {
        // //open file
        // std::ifstream m_file;
        // std::istream getInputStream() { return std::ifstream } }
        //use input
        //unique_ptr<AbstractInput> p;
        if(argc == 1) {// cerate function for process argc action,processArc
            //p = new ConsoleInput;

            //start receive command from user and use controller to control toy robot
            while (true) {
                std::string input;
                std::getline(std::cin, input);

                //                if(StringHelper::toUpper(command) == "QUIT") {// create quit cmd.  exit(0);
                //                    break;
                //                          }

                auto command = ToyRobot::InputParser::getInstance()->parse(input);
                if(command) {
                    (void)toyRobot->executeCommand(command.value());
                }
            }
        }
        //read from file
        else if(argc == 2) {//processArc
            //p = new FileInput;

            std::ifstream infile(argv[1]);
            if (infile.is_open()) {

                std::string command;
                while (std::getline(infile, command)) {
                    //                    toyRobotController->execute(command);
                }

                infile.close();
            }

        } else {
            return 1;
        }

        //std::istream = p.getInputStream()


    }  catch (...) {
        // try file open error
        std::cout << "Something wrong happened!" << std::endl;
        return 1;
    }

    return 0;
}
