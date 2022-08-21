#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "AbstractCommand.h"
#include <unordered_map>
#include <functional>

namespace ToyRobot
{

class Position;

class MoveCommand : public AbstractCommand
{
public:
    MoveCommand() = default;
    virtual ~MoveCommand() = default;

    virtual bool execute(ToyRobot* robot) override;

private:
    const static std::unordered_map<std::string, std::function<void(Position& position)>> m_moveFuncMap;
};

}

#endif // MOVECOMMAND_H
