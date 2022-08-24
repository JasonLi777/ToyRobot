#include "pch.h"
#include "../src/Command/PlaceCommandFactory.h"
#include "../src/Command/PlaceCommand.h"

namespace ToyRobot
{
    TEST(PlaceCommandFactoryTest, IsMatched)
    {
        std::unique_ptr<AbstractCommandFactory> placeCommandFactory = std::make_unique<PlaceCommandFactory>();

        EXPECT_FALSE(placeCommandFactory->isMatched(""));
        EXPECT_FALSE(placeCommandFactory->isMatched("ABC"));
        EXPECT_FALSE(placeCommandFactory->isMatched("PLACE 5,5,NORTH"));
        EXPECT_FALSE(placeCommandFactory->isMatched("place 0,0,north"));

        EXPECT_TRUE(placeCommandFactory->isMatched("PLACE 0,0,NORTH"));
        EXPECT_TRUE(placeCommandFactory->isMatched("PLACE 0,0,EAST"));
        EXPECT_TRUE(placeCommandFactory->isMatched("PLACE 0,0,SOUTH"));
        EXPECT_TRUE(placeCommandFactory->isMatched("PLACE 0,0,WEST"));
    }

    TEST(PlaceCommandFactoryTest, Build)
    {
        std::unique_ptr<AbstractCommandFactory> placeCommandFactory = std::make_unique<PlaceCommandFactory>();

        EXPECT_EQ(placeCommandFactory->build(""), nullptr);
        EXPECT_EQ(placeCommandFactory->build("ABC"), nullptr);
        EXPECT_EQ(placeCommandFactory->build("PLACE 5,5,NORTH"), nullptr);
        EXPECT_EQ(placeCommandFactory->build("place 0,0,north"), nullptr);

        EXPECT_NE(dynamic_cast<PlaceCommand*>(placeCommandFactory->build("PLACE 0,0,NORTH").get()), nullptr);
        EXPECT_NE(dynamic_cast<PlaceCommand*>(placeCommandFactory->build("PLACE 0,0,EAST").get()), nullptr);
        EXPECT_NE(dynamic_cast<PlaceCommand*>(placeCommandFactory->build("PLACE 0,0,SOUTH").get()), nullptr);
        EXPECT_NE(dynamic_cast<PlaceCommand*>(placeCommandFactory->build("PLACE 0,0,WEST").get()), nullptr);
    }

}
