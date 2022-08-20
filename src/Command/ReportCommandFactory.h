#ifndef REPORTCOMMANDFACTORY_H
#define REPORTCOMMANDFACTORY_H

#include "AbstractCommandFactory.h"

class ReportCommandFactory : public AbstractCommandFactory
{
public:
    ReportCommandFactory() = default;
    virtual ~ReportCommandFactory() = default;

    virtual std::optional<std::shared_ptr<AbstractCommand>> build(const std::string& command) const override;
};

#endif // REPORTCOMMANDFACTORY_H
