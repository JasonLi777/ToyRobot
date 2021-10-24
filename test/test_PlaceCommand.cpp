#include "pch.h"
#include "..\src\Command\AbstractCommand.h"
#include "..\src\Command\PlaceCommand.h"
#include "..\src\TableTop\TableTop.h"
#include "..\src\ToyRobot\ToyRobotStatus.h"

TEST(PlaceCommandTest, Place_Success)
{
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), direction);
    EXPECT_EQ(newStatus.position(), position);
    EXPECT_EQ(newStatus.tableTop(), tableTop);
}

TEST(PlaceCommandTest, Place_TableTop_Invalid)
{
    //table not valid, width and length are zero
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>(0, 0);
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    std::shared_ptr<AbstractCommand> placeCommand1 = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand1->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);

    //no table
    std::shared_ptr<AbstractCommand> placeCommand2 = std::make_shared<PlaceCommand>(nullptr, position, direction);
    newStatus = placeCommand2->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
}

TEST(PlaceCommandTest, Place_Direction_Invalid)
{
    //direction not valid
    Direction direction = Direction();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
}

TEST(PlaceCommandTest, Place_Position_Invalid)
{
    //position not valid
    Position position = Position(-1, -1);
    Direction direction = Direction(Direction::NORTH);
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
}

TEST(PlaceCommandTest, Place_Position_OutOfTable)
{
    //position not valid
    Position position = Position(5, 5);
    Direction direction = Direction(Direction::NORTH);
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
}
