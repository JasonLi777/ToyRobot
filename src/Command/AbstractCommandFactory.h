#ifndef ABSTRACTCOMMANDFACTORY_H
#define ABSTRACTCOMMANDFACTORY_H

#include <memory>
#include <string>

namespace ToyRobot
{

class AbstractCommand;

class AbstractCommandFactory
{
public:
    AbstractCommandFactory() = default;
    virtual ~AbstractCommandFactory() = default;

    virtual bool isMatched(const std::string& command) const = 0;

    virtual std::shared_ptr<AbstractCommand> build(const std::string& command) const = 0;
};

}

#endif // ABSTRACTCOMMANDFACTORY_H
