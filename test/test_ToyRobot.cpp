#include "pch.h"
#include "../src/ToyRobot/ToyRobot.h"
#include "../src/TableTop/TableTop.h"

namespace ToyRobot
{
    TEST(ToyRobotTest, Init_Default)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);
        EXPECT_EQ(toyRobot->getPosition(), Position());
        EXPECT_EQ(toyRobot->getDirection(), Direction());
        EXPECT_FALSE(toyRobot->isPlaced());
    }

    TEST(ToyRobotTest, Place)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        EXPECT_FALSE(toyRobot->place(Position(), Direction()));
        EXPECT_FALSE(toyRobot->isPlaced());

        EXPECT_FALSE(toyRobot->place(Position(0,0), Direction()));
        EXPECT_FALSE(toyRobot->isPlaced());

        EXPECT_FALSE(toyRobot->place(Position(), Direction("NORTH")));
        EXPECT_FALSE(toyRobot->isPlaced());

        EXPECT_TRUE(toyRobot->place(Position(0, 0), Direction("NORTH")));
        EXPECT_TRUE(toyRobot->isPlaced());
    }

    TEST(ToyRobotTest, Place_OutOfTable)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        EXPECT_FALSE(toyRobot->place(Position(5, 6), Direction("NORTH")));
        EXPECT_FALSE(toyRobot->isPlaced());
    }

    TEST(ToyRobotTest, Rotate_BeforePlaced)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        EXPECT_FALSE(toyRobot->rotate(Direction::TurnDirection::LEFT));
        EXPECT_FALSE(toyRobot->rotate(Direction::TurnDirection::RIGHT));
        EXPECT_FALSE(toyRobot->isPlaced());
    }

    TEST(ToyRobotTest, Rotate_Left)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        EXPECT_TRUE(toyRobot->place(Position(0, 0), Direction("NORTH")));

        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::LEFT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("WEST"));
        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::LEFT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("SOUTH"));
        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::LEFT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("EAST"));
        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::LEFT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));
    }

    TEST(ToyRobotTest, Rotate_Right)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        EXPECT_TRUE(toyRobot->place(Position(0, 0), Direction("NORTH")));

        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("EAST"));
        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("SOUTH"));
        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("WEST"));
        EXPECT_TRUE(toyRobot->rotate(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(toyRobot->getDirection(), Direction("NORTH"));
    }

    TEST(ToyRobotTest, Move_BeforePlaced)
    {
        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        EXPECT_FALSE(toyRobot->move());
        EXPECT_FALSE(toyRobot->isPlaced());
    }

    TEST(ToyRobotTest, Move)
    {
        struct TestData {
            Direction directon;
            Position startPos;
            Position posAfterMove;
            bool moveSuccess;
        };

        std::vector<TestData> vecTestData = {
            //move north
            {Direction("NORTH"), Position(1, 3), Position(1, 4), true},
            //prevent of failing
            {Direction("NORTH"), Position(1, 4), Position(1, 4), false},

            //move west
            {Direction("WEST"), Position(1, 2), Position(0, 2), true},
            //prevent of failing
            {Direction("WEST"), Position(0, 2), Position(0, 2), false},

            //move south
            {Direction("SOUTH"), Position(2, 1), Position(2, 0), true},
            //prevent of failing
            {Direction("SOUTH"), Position(2, 0), Position(2, 0), false},

            //move east
            {Direction("EAST"), Position(3, 1), Position(4, 1), true},
            //prevent of failing
            {Direction("EAST"), Position(4, 1), Position(4, 1), false},
        };

        auto tableTop = std::make_shared<TableTop>(5, 5);
        auto toyRobot = std::make_unique<ToyRobot>(tableTop);

        for (const TestData& testData : vecTestData) {

            EXPECT_TRUE(toyRobot->place(testData.startPos, testData.directon));
            EXPECT_EQ(toyRobot->move(), testData.moveSuccess);

            EXPECT_EQ(toyRobot->getDirection(), testData.directon);
            EXPECT_EQ(toyRobot->getPosition(), testData.posAfterMove);
        }
    }

}
