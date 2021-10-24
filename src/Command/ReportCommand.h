#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "AbstractCommand.h"
#include <string>

class ReportCommand : public AbstractCommand
{
public:
    ReportCommand();
    virtual ~ReportCommand();

    virtual ToyRobotStatus execute(const ToyRobotStatus& oldStatus) override;

    std::string getLastReport() const;

private:
    std::string m_lastReport;
};

#endif // REPORTCOMMAND_H
