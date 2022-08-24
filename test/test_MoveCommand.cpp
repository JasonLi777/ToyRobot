#include "pch.h"
#include "../src/Command/PlaceCommand.h"
#include "../src/Command/MoveCommand.h"
#include "../src/TableTop/TableTop.h"
#include "../src/ToyRobot/ToyRobot.h"

namespace ToyRobot
{
    TEST(MoveCommandTest, BeforePlaceCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        auto moveCommand = std::make_unique<MoveCommand>();

        EXPECT_FALSE(moveCommand->execute(toyRobot));
    }

    TEST(MoveCommandTest, MoveCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        auto placeCommand = std::make_unique<PlaceCommand>(Position(0, 0), Direction("NORTH"));
        auto moveCommand = std::make_unique<MoveCommand>();

        EXPECT_TRUE(placeCommand->execute(toyRobot));
        EXPECT_TRUE(moveCommand->execute(toyRobot));

        EXPECT_EQ(toyRobot->getPosition(), Position(0, 1));
    }

}
