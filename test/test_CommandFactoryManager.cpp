#include "pch.h"
#include "../src/Command/CommandFactoryManager.h"
#include "../src/Command/PlaceCommandFactory.h"
#include "../src/Command/ReportCommandFactory.h"
#include "../src/Command/MoveCommandFactory.h"
#include "../src/Command/RotateCommandFactory.h"

namespace ToyRobot
{
    TEST(CommandFactoryManagerTest, BuildCommand)
    {
        EXPECT_EQ(CommandFactoryManager::getInstance()->findFactory(""), nullptr);
        EXPECT_EQ(CommandFactoryManager::getInstance()->findFactory("ABC"), nullptr);

        EXPECT_NE(dynamic_cast<PlaceCommandFactory*>(CommandFactoryManager::getInstance()->findFactory("PLACE 0,0,NORTH").get()), nullptr);
        EXPECT_NE(dynamic_cast<MoveCommandFactory*>(CommandFactoryManager::getInstance()->findFactory("MOVE").get()), nullptr);
        EXPECT_NE(dynamic_cast<RotateCommandFactory*>(CommandFactoryManager::getInstance()->findFactory("LEFT").get()), nullptr);
        EXPECT_NE(dynamic_cast<RotateCommandFactory*>(CommandFactoryManager::getInstance()->findFactory("RIGHT").get()), nullptr);
        EXPECT_NE(dynamic_cast<ReportCommandFactory*>(CommandFactoryManager::getInstance()->findFactory("REPORT").get()), nullptr);
    }

}
