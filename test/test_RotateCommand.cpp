#include "pch.h"
#include "..\src\Command\AbstractCommand.h"
#include "..\src\Command\PlaceCommand.h"
#include "..\src\Command\RotateCommand.h"
#include "..\src\TableTop\TableTop.h"
#include "..\src\ToyRobot\ToyRobotStatus.h"

TEST(RotateCommandTest, Rotate_Left_Success)
{
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

    std::shared_ptr<AbstractCommand> rotateCommand = std::make_shared<RotateCommand>(Direction::LEFT);
    newStatus = rotateCommand->execute(newStatus);

    EXPECT_EQ(newStatus.direction(), Direction::WEST);
    EXPECT_EQ(newStatus.position(), position);
    EXPECT_EQ(newStatus.tableTop(), tableTop);
}

TEST(RotateCommandTest, Rotate_Right_Success)
{
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);
    ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

    std::shared_ptr<AbstractCommand> rotateCommand = std::make_shared<RotateCommand>(Direction::RIGHT);
    newStatus = rotateCommand->execute(newStatus);

    EXPECT_EQ(newStatus.direction(), Direction::EAST);
    EXPECT_EQ(newStatus.position(), position);
    EXPECT_EQ(newStatus.tableTop(), tableTop);
}


TEST(RotateCommandTest, Rotate_NotPlacedYet)
{
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    std::shared_ptr<AbstractCommand> rotateCommand = std::make_shared<RotateCommand>(Direction::RIGHT);
    ToyRobotStatus newStatus = rotateCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
}