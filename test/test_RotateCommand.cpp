#include "pch.h"
#include "../src/Command/PlaceCommand.h"
#include "../src/Command/RotateCommand.h"
#include "../src/TableTop/TableTop.h"
#include "../src/ToyRobot/ToyRobot.h"

namespace ToyRobot
{
    TEST(RotateCommandTest, BeforePlaceCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        std::unique_ptr<AbstractCommand> leftCommand = std::make_unique<RotateCommand>(Direction::TurnDirection::LEFT);
        std::unique_ptr<AbstractCommand> rightCommand = std::make_unique<RotateCommand>(Direction::TurnDirection::RIGHT);

        EXPECT_FALSE(leftCommand->execute(toyRobot));
        EXPECT_FALSE(rightCommand->execute(toyRobot));
    }

    TEST(RotateCommandTest, LeftCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        std::unique_ptr<AbstractCommand> leftCommand = std::make_unique<RotateCommand>(Direction::TurnDirection::LEFT);
        std::unique_ptr<AbstractCommand> placeCommand = std::make_unique<PlaceCommand>(Position(0, 0), Direction("NORTH"));

        EXPECT_TRUE(placeCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getPosition(), Position(0, 0));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));

        EXPECT_TRUE(leftCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("WEST"));
        EXPECT_TRUE(leftCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("SOUTH"));
        EXPECT_TRUE(leftCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("EAST"));
        EXPECT_TRUE(leftCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));
    }

    TEST(RotateCommandTest, RightCommand)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_shared<ToyRobot>(tableTop);

        std::unique_ptr<AbstractCommand> rightCommand = std::make_unique<RotateCommand>(Direction::TurnDirection::RIGHT);
        std::unique_ptr<AbstractCommand> placeCommand = std::make_unique<PlaceCommand>(Position(0, 0), Direction("NORTH"));

        EXPECT_TRUE(placeCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getPosition(), Position(0, 0));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));

        EXPECT_TRUE(rightCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("EAST"));
        EXPECT_TRUE(rightCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("SOUTH"));
        EXPECT_TRUE(rightCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("WEST"));
        EXPECT_TRUE(rightCommand->execute(toyRobot));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));
    }

}
