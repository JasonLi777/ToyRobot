#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "AbstractCommand.h"
#include <string>

namespace ToyRobot
{

class ReportCommand : public AbstractCommand
{
public:
    ReportCommand();
    virtual ~ReportCommand() = default;

    virtual bool execute(ToyRobot* robot) override;

    std::string getLastReport() const;

private:
    std::string m_lastReport;
};

}

#endif // REPORTCOMMAND_H
