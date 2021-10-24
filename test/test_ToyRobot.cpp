#include "pch.h"
#include "..\src\ToyRobot\ToyRobot.h"
#include "..\src\Command\AbstractCommand.h"
#include "..\src\Command\PlaceCommand.h"
#include "..\src\TableTop\TableTop.h"

TEST(ToyRobotTest, Init_Default)
{
    ToyRobot toyRobot = ToyRobot();
    EXPECT_EQ(toyRobot.status(), ToyRobotStatus());
}

TEST(ToyRobotTest, ExecuteCommand)
{
    ToyRobot toyRobot = ToyRobot();

    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();
    Position position = Position(0, 0);
    Direction direction = Direction(Direction::NORTH);

    std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, position, direction);

    toyRobot.executeCommand(placeCommand);

    EXPECT_EQ(toyRobot.status().direction(), direction);
    EXPECT_EQ(toyRobot.status().position(), position);
    EXPECT_EQ(toyRobot.status().tableTop(), tableTop);

    //invalid command
    toyRobot.executeCommand(nullptr);
    EXPECT_EQ(toyRobot.status().direction(), direction);
    EXPECT_EQ(toyRobot.status().position(), position);
    EXPECT_EQ(toyRobot.status().tableTop(), tableTop);
}

