#ifndef MOVECOMMANDFACTORY_H
#define MOVECOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

namespace ToyRobot
{

class MoveCommandFactory : public AbstractCommandFactory
{
public:
    MoveCommandFactory() = default;
    virtual ~MoveCommandFactory() = default;

    virtual std::shared_ptr<AbstractCommand> build(const std::string& command) const override;
};

}

#endif // MOVECOMMANDFACTORY_H
