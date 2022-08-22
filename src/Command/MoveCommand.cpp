#include "MoveCommand.h"
#include "../ToyRobot/ToyRobot.h"

namespace ToyRobot
{

const std::unordered_map<std::string, std::function<void(Position& position)>> MoveCommand::m_moveFuncMap =
{
    {
        "NORTH", 
        [](Position& position) { position.setY(position.getY() + 1); }
    },
    {
        "WEST",
        [](Position& position) { position.setX(position.getX() - 1); }
    },
    {
        "SOUTH",
        [](Position& position) { position.setY(position.getY() - 1); }
    },
    {
        "EAST",
        [](Position& position) { position.setX(position.getX() + 1); }
    },
};

bool MoveCommand::execute(ToyRobot *robot)
{
    if(!robot || !robot->isPlaced())
    {
        return false;
    }

    auto position = robot->getPosition();

    auto itr = m_moveFuncMap.find(robot->getDirection().toString());
    if(itr == m_moveFuncMap.end())
    {
        return false;
    }

    itr->second(position);

    return robot->setPosition(position);
}

}
