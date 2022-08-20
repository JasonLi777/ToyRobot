#ifndef MOVECOMMANDFACTORY_H
#define MOVECOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

class MoveCommandFactory : public AbstractCommandFactory
{
public:
    MoveCommandFactory() = default;
    virtual ~MoveCommandFactory() = default;

    virtual std::optional<std::shared_ptr<AbstractCommand>> build(const std::string& command) const override;
};

#endif // MOVECOMMANDFACTORY_H
