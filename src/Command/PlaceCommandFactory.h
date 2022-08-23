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

    virtual bool isMatched(const std::string& command) const override;

    virtual std::shared_ptr<AbstractCommand> build(const std::string& command) const override;

private:
    static const std::string m_matchRegex;
};

}

#endif // PLACECOMMANDFACTORY_H
