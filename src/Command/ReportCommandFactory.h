#ifndef REPORTCOMMANDFACTORY_H
#define REPORTCOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

namespace ToyRobot
{

class ReportCommandFactory : public AbstractCommandFactory
{
public:
    ReportCommandFactory() = default;
    virtual ~ReportCommandFactory() = default;

    virtual std::shared_ptr<AbstractCommand> build(const std::string& command) const override;
};

}

#endif // REPORTCOMMANDFACTORY_H
