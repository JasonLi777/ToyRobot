#include "pch.h"
#include "..\src\TableTop\TableTop.h"
#include "..\src\ToyRobot\ToyRobotStatus.h"

TEST(ToyRobotStatusTest, Init_Default)
{
    ToyRobotStatus status = ToyRobotStatus();

    EXPECT_EQ(status.direction(), Direction());
    EXPECT_EQ(status.position(), Position());
    EXPECT_EQ(status.tableTop(), nullptr);
}

TEST(ToyRobotStatusTest, SetTableTop)
{
    ToyRobotStatus status = ToyRobotStatus();

    std::shared_ptr<TableTop> tableTop1 = std::make_shared<TableTop>();
    status.setTableTop(tableTop1);
    EXPECT_EQ(status.tableTop(), tableTop1);

    std::shared_ptr<TableTop> tableTop2 = std::make_shared<TableTop>();
    status.setTableTop(tableTop2);
    EXPECT_EQ(status.tableTop(), tableTop2);
}

TEST(ToyRobotStatusTest, SetPosition)
{
    ToyRobotStatus status = ToyRobotStatus();

    Position position1 = Position(0, 0);
    status.setPosition(position1);
    EXPECT_EQ(status.position(), position1);

    Position position2 = Position(1, 1);
    status.setPosition(position2);
    EXPECT_EQ(status.position(), position2);
}

TEST(ToyRobotStatusTest, SetDirection)
{
    ToyRobotStatus status = ToyRobotStatus();

    Direction direction1 = Direction(Direction::NORTH);
    status.setDirection(direction1);
    EXPECT_EQ(status.direction(), direction1);

    Direction direction2 = Direction(Direction::SOUTH);
    status.setDirection(direction2);
    EXPECT_EQ(status.direction(), direction2);
}

TEST(ToyRobotStatusTest, IsValid_Valid)
{
    ToyRobotStatus status = ToyRobotStatus();
    status.setTableTop(std::make_shared<TableTop>());
    status.setDirection(Direction(Direction::NORTH));
    status.setPosition(Position(0, 0));

    EXPECT_TRUE(status.isValid());
}

TEST(ToyRobotStatusTest, IsValid_PositionInvalid)
{
    ToyRobotStatus status = ToyRobotStatus();
    status.setTableTop(std::make_shared<TableTop>());
    status.setDirection(Direction(Direction::NORTH));

    EXPECT_FALSE(status.isValid());
}

TEST(ToyRobotStatusTest, IsValid_DirectionInvalid)
{
    ToyRobotStatus status = ToyRobotStatus();
    status.setTableTop(std::make_shared<TableTop>());
    status.setPosition(Position(0, 0));

    EXPECT_FALSE(status.isValid());
}

TEST(ToyRobotStatusTest, IsValid_TableInvalid)
{
    ToyRobotStatus status = ToyRobotStatus();
    status.setDirection(Direction(Direction::NORTH));
    status.setPosition(Position(0, 0));

    EXPECT_FALSE(status.isValid());
}

TEST(ToyRobotStatusTest, IsValid_PositionNotOnTheTable)
{
    ToyRobotStatus status = ToyRobotStatus();
    status.setTableTop(std::make_shared<TableTop>());
    status.setDirection(Direction(Direction::NORTH));
    status.setPosition(Position(5, 5));

    EXPECT_FALSE(status.isValid());
}