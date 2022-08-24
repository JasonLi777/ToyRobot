#include "pch.h"
#include "../src/Command/MoveCommandFactory.h"
#include "../src/Command/MoveCommand.h"

namespace ToyRobot
{
    TEST(MoveCommandFactoryTest, IsMatched)
    {
        std::unique_ptr<AbstractCommandFactory> moveCommandFactory = std::make_unique<MoveCommandFactory>();

        EXPECT_FALSE(moveCommandFactory->isMatched(""));
        EXPECT_FALSE(moveCommandFactory->isMatched("ABC"));
        EXPECT_FALSE(moveCommandFactory->isMatched("move"));

        EXPECT_TRUE(moveCommandFactory->isMatched("MOVE"));
    }

    TEST(MoveCommandFactoryTest, Build)
    {
        std::unique_ptr<AbstractCommandFactory> moveCommandFactory = std::make_unique<MoveCommandFactory>();

        EXPECT_EQ(moveCommandFactory->build(""), nullptr);
        EXPECT_EQ(moveCommandFactory->build("ABC"), nullptr);
        EXPECT_EQ(moveCommandFactory->build("move"), nullptr);

        EXPECT_NE(dynamic_cast<MoveCommand*>(moveCommandFactory->build("MOVE").get()), nullptr);
    }

}
