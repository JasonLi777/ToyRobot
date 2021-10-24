#include "pch.h"
#include "..\src\Util\Direction.h"

TEST(DirectionTest, Init_Default)
{
    Direction direction = Direction();
    EXPECT_EQ(direction.value(), Direction::INVALID);
}

TEST(DirectionTest, Init_FromString)
{
    Direction direction = Direction::fromString("");
    EXPECT_EQ(direction.value(), Direction::INVALID);

    direction = Direction::fromString("ABC");
    EXPECT_EQ(direction.value(), Direction::INVALID);

    direction = Direction::fromString("NORTH");
    EXPECT_EQ(direction.value(), Direction::NORTH);

    direction = Direction::fromString("WEST");
    EXPECT_EQ(direction.value(), Direction::WEST);

    direction = Direction::fromString("SOUTH");
    EXPECT_EQ(direction.value(), Direction::SOUTH);

    direction = Direction::fromString("EAST");
    EXPECT_EQ(direction.value(), Direction::EAST);
}

TEST(DirectionTest, Init_NORTH)
{
    Direction direction = Direction(Direction::NORTH);
    EXPECT_EQ(direction.value(), Direction::NORTH);
}

TEST(DirectionTest, Init_WEST)
{
    Direction direction = Direction(Direction::WEST);
    EXPECT_EQ(direction.value(), Direction::WEST);
}

TEST(DirectionTest, Init_SOUTH)
{
    Direction direction = Direction(Direction::SOUTH);
    EXPECT_EQ(direction.value(), Direction::SOUTH);
}

TEST(DirectionTest, Init_EAST)
{
    Direction direction = Direction(Direction::EAST);
    EXPECT_EQ(direction.value(), Direction::EAST);
}

TEST(DirectionTest, SetValue_Invalid)
{
    Direction direction = Direction(Direction::NORTH);
    direction.setValue(Direction::INVALID);
    EXPECT_EQ(direction.value(), Direction::INVALID);
}

TEST(DirectionTest, SetValue_Valid)
{
    Direction direction = Direction();
    EXPECT_EQ(direction.value(), Direction::INVALID);

    direction.setValue(Direction::NORTH);
    EXPECT_EQ(direction.value(), Direction::NORTH);

    direction.setValue(Direction::WEST);
    EXPECT_EQ(direction.value(), Direction::WEST);

    direction.setValue(Direction::SOUTH);
    EXPECT_EQ(direction.value(), Direction::SOUTH);

    direction.setValue(Direction::EAST);
    EXPECT_EQ(direction.value(), Direction::EAST);
}

TEST(DirectionTest, ToString)
{
    Direction direction = Direction(Direction::INVALID);
    EXPECT_EQ(direction.toString(), "INVALID");

    direction.setValue(Direction::NORTH);
    EXPECT_EQ(direction.toString(), "NORTH");

    direction.setValue(Direction::WEST);
    EXPECT_EQ(direction.toString(), "WEST");

    direction.setValue(Direction::SOUTH);
    EXPECT_EQ(direction.toString(), "SOUTH");

    direction.setValue(Direction::EAST);
    EXPECT_EQ(direction.toString(), "EAST");
}


TEST(DirectionTest, IsValid)
{
    Direction direction = Direction(Direction::INVALID);
    EXPECT_FALSE(direction.isValid());

    direction.setValue(Direction::NORTH);
    EXPECT_TRUE(direction.isValid());

    direction.setValue(Direction::WEST);
    EXPECT_TRUE(direction.isValid());

    direction.setValue(Direction::SOUTH);
    EXPECT_TRUE(direction.isValid());

    direction.setValue(Direction::EAST);
    EXPECT_TRUE(direction.isValid());
}

TEST(DirectionTest, Turn_Invalid)
{
    Direction direction = Direction(Direction::INVALID);
    EXPECT_FALSE(direction.turn(Direction::LEFT));
    EXPECT_FALSE(direction.turn(Direction::RIGHT));
}

TEST(DirectionTest, Turn_Left)
{
    Direction direction = Direction(Direction::NORTH);
    EXPECT_TRUE(direction.turn(Direction::LEFT));
    EXPECT_EQ(direction.value(), Direction::WEST);

    EXPECT_TRUE(direction.turn(Direction::LEFT));
    EXPECT_EQ(direction.value(), Direction::SOUTH);

    EXPECT_TRUE(direction.turn(Direction::LEFT));
    EXPECT_EQ(direction.value(), Direction::EAST);

    EXPECT_TRUE(direction.turn(Direction::LEFT));
    EXPECT_EQ(direction.value(), Direction::NORTH);
}

TEST(DirectionTest, Turn_Right)
{
    Direction direction = Direction(Direction::NORTH);
    EXPECT_TRUE(direction.turn(Direction::RIGHT));
    EXPECT_EQ(direction.value(), Direction::EAST);

    EXPECT_TRUE(direction.turn(Direction::RIGHT));
    EXPECT_EQ(direction.value(), Direction::SOUTH);

    EXPECT_TRUE(direction.turn(Direction::RIGHT));
    EXPECT_EQ(direction.value(), Direction::WEST);

    EXPECT_TRUE(direction.turn(Direction::RIGHT));
    EXPECT_EQ(direction.value(), Direction::NORTH);
}




