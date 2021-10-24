#include "pch.h"
#include "..\src\Command\AbstractCommand.h"
#include "..\src\Command\PlaceCommand.h"
#include "..\src\Command\MoveCommand.h"
#include "..\src\TableTop\TableTop.h"
#include "..\src\ToyRobot\ToyRobotStatus.h"

TEST(MoveCommandTest, Move_Success_And_Not_Fall)
{
    struct TestData {
        Direction directon;
        Position startPos;
        Position posAfterMove;
    };

    std::vector<TestData> vecTestData = {
        //move north
        {Direction(Direction::NORTH), Position(1, 3), Position(1, 4)},
        {Direction(Direction::NORTH), Position(1, 4), Position(1, 4)},//prevent of failing

        //move west
        {Direction(Direction::WEST), Position(1, 2), Position(0, 2)},
        {Direction(Direction::WEST), Position(0, 2), Position(0, 2)},//prevent of failing

        //move south
        {Direction(Direction::SOUTH), Position(2, 1), Position(2, 0)},
        {Direction(Direction::SOUTH), Position(2, 0), Position(2, 0)},//prevent of failing

        //move east
        {Direction(Direction::EAST), Position(3, 1), Position(4, 1)},
        {Direction(Direction::EAST), Position(4, 1), Position(4, 1)},//prevent of failing
    };

    std::shared_ptr<TableTop> tableTop = std::make_shared<TableTop>();

    //run all test data
    for (TestData testData : vecTestData) {

        std::shared_ptr<AbstractCommand> placeCommand = std::make_shared<PlaceCommand>(tableTop, testData.startPos, testData.directon);
        ToyRobotStatus newStatus = placeCommand->execute(ToyRobotStatus());

        std::shared_ptr<AbstractCommand> moveCommand = std::make_shared<MoveCommand>();
        newStatus = moveCommand->execute(newStatus);

        EXPECT_EQ(newStatus.direction(), testData.directon);
        EXPECT_EQ(newStatus.position(), testData.posAfterMove);
        EXPECT_EQ(newStatus.tableTop(), tableTop);
    }
}

TEST(MoveCommandTest, Move_Failed_Not_Placed_Yet)
{
    std::shared_ptr<AbstractCommand> moveCommand = std::make_shared<MoveCommand>();
    ToyRobotStatus newStatus = moveCommand->execute(ToyRobotStatus());

    EXPECT_EQ(newStatus.direction(), Direction());
    EXPECT_EQ(newStatus.position(), Position());
    EXPECT_EQ(newStatus.tableTop(), nullptr);
}
