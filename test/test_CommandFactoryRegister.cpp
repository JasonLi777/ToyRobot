#include "pch.h"
#include "../src/Command/CommandFactoryManager.h"
#include "../src/Command/PlaceCommand.h"
#include "../src/Command/ReportCommand.h"
#include "../src/Command/MoveCommand.h"
#include "../src/Command/RotateCommand.h"

namespace ToyRobot
{
    TEST(CommandFactoryManagerTest, BuildCommand)
    {
        EXPECT_EQ(CommandFactoryManager::getInstance()->buildCommand(""), nullptr);
        EXPECT_EQ(CommandFactoryManager::getInstance()->buildCommand("ABC"), nullptr);

        EXPECT_NE(dynamic_cast<PlaceCommand*>(CommandFactoryManager::getInstance()->buildCommand("PLACE 0,0,NORTH").get()), nullptr);
        EXPECT_NE(dynamic_cast<MoveCommand*>(CommandFactoryManager::getInstance()->buildCommand("MOVE").get()), nullptr);
        EXPECT_NE(dynamic_cast<RotateCommand*>(CommandFactoryManager::getInstance()->buildCommand("LEFT").get()), nullptr);
        EXPECT_NE(dynamic_cast<RotateCommand*>(CommandFactoryManager::getInstance()->buildCommand("RIGHT").get()), nullptr);
        EXPECT_NE(dynamic_cast<ReportCommand*>(CommandFactoryManager::getInstance()->buildCommand("REPORT").get()), nullptr);
    }

}
