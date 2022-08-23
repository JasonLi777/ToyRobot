#include <iostream>
#include <string>
#include "ToyRobot/ToyRobot.h"
#include "TableTop/TableTop.h"
#include "Command/InputParser.h"
#include "InputHandler/ConsoleInputHandler.h"
#include "InputHandler/FileInputHandler.h"
#include "Command/AbstractCommand.h"

std::unique_ptr<ToyRobot::AbstractInputHandler> createInputHandler(int argc, char *argv[])
{
    if(argc == 1)
    {
        return std::make_unique<ToyRobot::ConsoleInputHandler>();
    }
    else if(argc == 2)
    {
        return std::make_unique<ToyRobot::FileInputHandler>(argv[1]);
    }
    else
    {
        return nullptr;
    }
}

const int s_defaultTableTopWidth = 5;
const int s_defaultTableTopLength = 5;

int main(int argc, char *argv[])
{
    try {
        std::cout << "Command:" << std::endl;
        std::cout << "   PLACE X,Y,F" << std::endl;
        std::cout << "   MOVE" << std::endl;
        std::cout << "   LEFT" << std::endl;
        std::cout << "   RIGHT" << std::endl;
        std::cout << "   REPORT" << std::endl;
        std::cout << "Please enter the above commands to control the toy robot." << std::endl << std::endl;

        auto inputHandler = createInputHandler(argc, argv);
        if(!inputHandler)
        {
            return 1;
        }

        auto tableTop = std::make_shared<ToyRobot::TableTop>(s_defaultTableTopWidth, s_defaultTableTopLength);
        auto toyRobot = std::make_shared<ToyRobot::ToyRobot>(tableTop);

        std::string input;
        while(inputHandler->getLine(input))
        {
            auto command = ToyRobot::InputParser::getInstance()->parse(input);
            if(command)
            {
                command->execute(toyRobot);
            }
            else
            {
                std::cout << "Invalid input!" << std::endl;
            }
        }
    }
    catch(...)
    {
        std::cout << "Something wrong happened!" << std::endl;
        return 1;
    }

    return 0;
}
