#include "pch.h"
#include "..\src\Command\AbstractCommand.h"
#include "..\src\Command\ReportCommand.h"
#include "..\src\TableTop\TableTop.h"
#include "..\src\ToyRobot\ToyRobotStatus.h"

TEST(ReportCommandTest, Report_Success)
{
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    ToyRobotStatus newStatus = ToyRobotStatus();
    newStatus.setTableTop(tableTop);
    newStatus.setPosition(position);
    newStatus.setDirection(direction);

    std::shared_ptr<ReportCommand> reportCommand = std::make_shared<ReportCommand>();
    newStatus = reportCommand->execute(newStatus);

    EXPECT_EQ(newStatus.direction(), direction);
    EXPECT_EQ(newStatus.position(), position);
    EXPECT_EQ(newStatus.tableTop(), tableTop);
    EXPECT_EQ(reportCommand->getLastReport(), "0,0,NORTH");
}

TEST(ReportCommandTest, Report_Fail_Not_Placed_Yet)
{
    std::shared_ptr<ReportCommand> reportCommand = std::make_shared<ReportCommand>();
    ToyRobotStatus newStatus = reportCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
    EXPECT_EQ(reportCommand->getLastReport(), "");
}
