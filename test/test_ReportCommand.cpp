#include "pch.h"
#include "../src/Command/ReportCommand.h"
#include "../src/Command/PlaceCommand.h"
#include "../src/TableTop/TableTop.h"
#include "../src/ToyRobot/ToyRobot.h"

namespace ToyRobot
{
    TEST(ReportCommandTest, BeforePlaceCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        auto reportCommand = std::make_unique<ReportCommand>();

        EXPECT_FALSE(reportCommand->execute(toyRobot));
        EXPECT_EQ(reportCommand->getLastReport(), "");
    }

    TEST(ReportCommandTest, ReportCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        std::unique_ptr<AbstractCommand> placeCommand = std::make_unique<PlaceCommand>(Position(0, 0), Direction("NORTH"));
        std::unique_ptr<ReportCommand> reportCommand = std::make_unique<ReportCommand>();

        EXPECT_TRUE(placeCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getPosition(), Position(0, 0));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));
        EXPECT_TRUE(reportCommand->execute(toyRobot));
        EXPECT_EQ(reportCommand->getLastReport(), "0,0,NORTH");
    }

}
