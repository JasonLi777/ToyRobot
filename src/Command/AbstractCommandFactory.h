#ifndef ABSTRACTCOMMANDFACTORY_H
#define ABSTRACTCOMMANDFACTORY_H

#include <optional>
#include <memory>
#include <string>

class AbstractCommand;

class AbstractCommandFactory
{
public:
    AbstractCommandFactory() = default;
    virtual ~AbstractCommandFactory() = default;

    virtual std::optional<std::shared_ptr<AbstractCommand>> build(const std::string& command) const = 0;
};

#endif // ABSTRACTCOMMANDFACTORY_H
