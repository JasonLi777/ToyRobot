#ifndef PLACECOMMANDFACTORY_H
#define PLACECOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

namespace ToyRobot
{

class PlaceCommandFactory : public AbstractCommandFactory
{
public:
    PlaceCommandFactory() = default;
    virtual ~PlaceCommandFactory() = default;

    virtual std::optional<std::shared_ptr<AbstractCommand>> build(const std::string& command) const override;
};

}

#endif // PLACECOMMANDFACTORY_H
