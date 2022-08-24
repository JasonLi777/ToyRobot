#include "pch.h"
#include "../src/ToyRobot/Direction.h"

namespace ToyRobot
{
    TEST(DirectionTest, Init_Default)
    {
        Direction direction = Direction();
        EXPECT_FALSE(direction.isValid());
    }

    TEST(DirectionTest, Init_FromString)
    {
        Direction direction = Direction("");
        EXPECT_FALSE(direction.isValid());

        direction = Direction("ABC");
        EXPECT_FALSE(direction.isValid());

        direction = Direction("NORTH");
        EXPECT_TRUE(direction.isValid());

        direction = Direction("WEST");
        EXPECT_TRUE(direction.isValid());

        direction = Direction("SOUTH");
        EXPECT_TRUE(direction.isValid());

        direction = Direction("EAST");
        EXPECT_TRUE(direction.isValid());
    }

    TEST(DirectionTest, ToString)
    {
        Direction direction = Direction("");
        EXPECT_EQ(direction.toString(), "");

        direction = Direction("ABC");
        EXPECT_EQ(direction.toString(), "");

        direction = Direction("NORTH");
        EXPECT_EQ(direction.toString(), "NORTH");

        direction = Direction("WEST");
        EXPECT_EQ(direction.toString(), "WEST");

        direction = Direction("SOUTH");
        EXPECT_EQ(direction.toString(), "SOUTH");

        direction = Direction("EAST");
        EXPECT_EQ(direction.toString(), "EAST");
    }

    TEST(DirectionTest, Turn_Invalid)
    {
        Direction direction = Direction("");
        EXPECT_FALSE(direction.turn(Direction::TurnDirection::LEFT));
        EXPECT_FALSE(direction.turn(Direction::TurnDirection::RIGHT));
    }

    TEST(DirectionTest, Turn_Left)
    {
        Direction direction = Direction("NORTH");
        EXPECT_TRUE(direction.turn(Direction::TurnDirection::LEFT));
        EXPECT_EQ(direction.toString(), "WEST");

        EXPECT_TRUE(direction.turn(Direction::TurnDirection::LEFT));
        EXPECT_EQ(direction.toString(), "SOUTH");

        EXPECT_TRUE(direction.turn(Direction::TurnDirection::LEFT));
        EXPECT_EQ(direction.toString(), "EAST");

        EXPECT_TRUE(direction.turn(Direction::TurnDirection::LEFT));
        EXPECT_EQ(direction.toString(), "NORTH");
    }

    TEST(DirectionTest, Turn_Right)
    {
        Direction direction = Direction("NORTH");
        EXPECT_TRUE(direction.turn(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(direction.toString(), "EAST");

        EXPECT_TRUE(direction.turn(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(direction.toString(), "SOUTH");

        EXPECT_TRUE(direction.turn(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(direction.toString(), "WEST");

        EXPECT_TRUE(direction.turn(Direction::TurnDirection::RIGHT));
        EXPECT_EQ(direction.toString(), "NORTH");
    }

}
