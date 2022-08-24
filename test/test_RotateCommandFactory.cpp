#include "pch.h"
#include "../src/Command/RotateCommandFactory.h"
#include "../src/Command/RotateCommand.h"

namespace ToyRobot
{
    TEST(RotateCommandFactoryTest, IsMatched)
    {
        std::unique_ptr<AbstractCommandFactory> rotateCommandFactory = std::make_unique<RotateCommandFactory>();

        EXPECT_FALSE(rotateCommandFactory->isMatched(""));
        EXPECT_FALSE(rotateCommandFactory->isMatched("ABC"));
        EXPECT_FALSE(rotateCommandFactory->isMatched("left"));
        EXPECT_FALSE(rotateCommandFactory->isMatched("right"));

        EXPECT_TRUE(rotateCommandFactory->isMatched("LEFT"));
        EXPECT_TRUE(rotateCommandFactory->isMatched("RIGHT"));
    }

    TEST(RotateCommandFactoryTest, Build)
    {
        std::unique_ptr<AbstractCommandFactory> rotateCommandFactory = std::make_unique<RotateCommandFactory>();

        EXPECT_EQ(rotateCommandFactory->build(""), nullptr);
        EXPECT_EQ(rotateCommandFactory->build("ABC"), nullptr);
        EXPECT_EQ(rotateCommandFactory->build("left"), nullptr);
        EXPECT_EQ(rotateCommandFactory->build("right"), nullptr);

        EXPECT_NE(dynamic_cast<RotateCommand*>(rotateCommandFactory->build("LEFT").get()), nullptr);
        EXPECT_NE(dynamic_cast<RotateCommand*>(rotateCommandFactory->build("RIGHT").get()), nullptr);
    }

}
