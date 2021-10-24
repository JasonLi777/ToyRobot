#include "pch.h"
#include "..\src\ToyRobot\ToyRobot.h"
#include "..\src\TableTop\TableTop.h"
#include "..\src\ToyRobot\ToyRobotController.h"
#include "..\src\Command\AbstractCommand.h"
#include "..\src\Command\PlaceCommand.h"
#include "..\src\Command\MoveCommand.h"
#include "..\src\Command\ReportCommand.h"
#include "..\src\Command\RotateCommand.h"

TEST(ToyRobotControllerTest, Init_Default)
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot, tableTop);
    EXPECT_EQ(toyRobotController.toyRobot(), toyRobot);
    EXPECT_EQ(toyRobotController.tableTop(), tableTop);
}

TEST(ToyRobotControllerTest, Execute_Success)
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot, tableTop);
    EXPECT_TRUE(toyRobotController.execute("RIGHT"));
}

TEST(ToyRobotControllerTest, Execute_Without_TableTop)
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot);
    EXPECT_FALSE(toyRobotController.execute("RIGHT"));
}

TEST(ToyRobotControllerTest, Execute_With_Invalid_ToyRobot)
{
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(nullptr, tableTop);
    EXPECT_FALSE(toyRobotController.execute("RIGHT"));
}

TEST(ToyRobotControllerTest, Parse_Place_Command_Success)
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot, tableTop);

    //place command
    std::shared_ptr<AbstractCommand> command = toyRobotController.parseCommand("PLACE 0,0,NORTH");
    PlaceCommand* placeCommand = dynamic_cast<PlaceCommand*>(command.get());
    EXPECT_NE(placeCommand, nullptr);
    if (placeCommand) {
        EXPECT_EQ(placeCommand->direction(), Direction(Direction::NORTH));
        EXPECT_EQ(placeCommand->position(), Position(0, 0));
        EXPECT_EQ(placeCommand->tableTop(), tableTop);
    }
}

TEST(ToyRobotControllerTest, Parse_Move_Command_Success)
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot, tableTop);

    //move command
    std::shared_ptr<AbstractCommand> command = toyRobotController.parseCommand("MOVE");
    MoveCommand* moveCommand = dynamic_cast<MoveCommand*>(command.get());
    EXPECT_NE(moveCommand, nullptr);
}

TEST(ToyRobotControllerTest, Parse_Rotate_Command_Success)
{
    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot, tableTop);

    //left command
    std::shared_ptr<AbstractCommand> command = toyRobotController.parseCommand("LEFT");
    RotateCommand* rotateCommand = dynamic_cast<RotateCommand*>(command.get());
    EXPECT_NE(rotateCommand, nullptr);
    if (rotateCommand) {
        EXPECT_EQ(rotateCommand->direction(), Direction::LEFT);
    }

    command = toyRobotController.parseCommand("RIGHT");
    rotateCommand = dynamic_cast<RotateCommand*>(command.get());
    EXPECT_NE(rotateCommand, nullptr);
    if (rotateCommand) {
        EXPECT_EQ(rotateCommand->direction(), Direction::RIGHT);
    }
}

TEST(ToyRobotControllerTest, Parse_Command_Failed)
{
    std::vector<std::string> vecInvalidCommand = {
        "PLACE",
        "PLACE 1",
        "PLACE 1,2",
        "PLACE -1,2,NORTH",
        "PLACE 1,2,NORTH,NEW ZEALAND",
        "  PLACE   1,  2,  NORTH  ",
        "PLACE a,2,WEST",
        "MOVE 123",
        "123 MOVE",
        "LEFT 123",
        "123 LEFT",
        "RIGHT 123",
        " 123 RIGHT",
        "REPORT 123",
        " 123 REPORT"
    };

    std::shared_ptr<ToyRobot> toyRobot = std::make_shared<ToyRobot>();
    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    ToyRobotController toyRobotController = ToyRobotController(toyRobot, tableTop);

    //leading char and end char not match
    for (std::string s : vecInvalidCommand) {
        std::shared_ptr<AbstractCommand> command = toyRobotController.parseCommand(s);
        EXPECT_EQ(command, nullptr);
    }
}


