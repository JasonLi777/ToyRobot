#ifndef ROTATECOMMANDFACTORY_H
#define ROTATECOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

namespace ToyRobot
{

class RotateCommandFactory : public AbstractCommandFactory
{
public:
    RotateCommandFactory() = default;
    virtual ~RotateCommandFactory() = default;

    virtual std::shared_ptr<AbstractCommand> build(const std::string& command) const override;
};

}

#endif // ROTATECOMMANDFACTORY_H
