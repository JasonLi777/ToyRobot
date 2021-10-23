#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "AbstractCommand.h"

class ReportCommand : public AbstractCommand
{
public:
    ReportCommand();
    virtual ~ReportCommand();

    virtual ToyRobotStatus execute(const ToyRobotStatus& oldStatus) override;
};

#endif // REPORTCOMMAND_H
