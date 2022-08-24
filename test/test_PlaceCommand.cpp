#include "pch.h"
#include "../src/Command/PlaceCommand.h"
#include "../src/TableTop/TableTop.h"
#include "../src/ToyRobot/ToyRobot.h"

namespace ToyRobot
{
    TEST(PlaceCommandTest, PlaceCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);
        std::unique_ptr<AbstractCommand> placeCommand = std::make_unique<PlaceCommand>(Position(0, 0), Direction("NORTH"));

        EXPECT_TRUE(placeCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getPosition(), Position(0, 0));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));

        //second place command
        placeCommand = std::make_unique<PlaceCommand>(Position(2, 3), Direction("WEST"));
        EXPECT_TRUE(placeCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getPosition(), Position(2, 3));
        EXPECT_EQ(toyRobot->getDirection(), Direction("WEST"));
    }

    TEST(PlaceCommandTest, Place_InvalidLocation)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);
        std::unique_ptr<AbstractCommand> placeCommand = std::make_unique<PlaceCommand>(Position(5, 5), Direction("NORTH"));

        EXPECT_FALSE(placeCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getPosition(), Position(-1, -1));
        EXPECT_EQ(toyRobot->getDirection(), Direction());
    }
}
