#include "pch.h"
#include "../src/ToyRobot/Position.h"
#include <vector>

namespace ToyRobot
{

    TEST(PositionTest, Init_Default)
    {
        Position position = Position();

        EXPECT_EQ(position.getX(), -1);
        EXPECT_EQ(position.getY(), -1);
        EXPECT_FALSE(position.isValid());
    }

    TEST(PositionTest, Init_WithValidValue)
    {
        int x = 1;
        int y = 2;
        Position position = Position(x, y);

        EXPECT_EQ(position.getX(), x);
        EXPECT_EQ(position.getY(), y);
        EXPECT_TRUE(position.isValid());
    }

    TEST(PositionTest, Init_WithInvalidValue)
    {
        int x = -1;
        int y = -2;

        Position position = Position(x, y);

        EXPECT_EQ(x, position.getX());
        EXPECT_EQ(y, position.getY());
        EXPECT_FALSE(position.isValid());
    }

    TEST(PositionTest, SetX_WithValidValue)
    {
        Position position = Position(0, 0);

        std::vector<int> vecX = { 0, 1, 2, 3, 4 };

        for(int newX : vecX)
        {
            position.setX(newX);
            EXPECT_EQ(position.getX(), newX);
        }
    }

    TEST(PositionTest, SetX_WithInvalidValue)
    {
        Position position = Position(0, 0);

        std::vector<int> vecX = { -1, -2, -3 };

        for(int newX : vecX)
        {
            position.setX(newX);
            EXPECT_EQ(position.getX(), newX);
        }
    }

    TEST(PositionTest, SetY_WithValidValue)
    {
        Position position = Position(0, 0);

        std::vector<int> vecY = { 0, 1, 2, 3, 4 };

        for(int newY : vecY)
        {
            position.setY(newY);
            EXPECT_EQ(position.getY(), newY);
        }
    }

    TEST(PositionTest, SetY_WithInvalidValue)
    {
        Position position = Position(0, 0);

        std::vector<int> vecY = { -1, -2, -3 };

        for(int newY : vecY)
        {
            position.setY(newY);
            EXPECT_EQ(position.getY(), newY);
        }
    }

    TEST(PositionTest, IsValid)
    {
        Position position = Position(0, 0);

        std::vector<std::pair<int, int>> vecPos = { {0, 0}, {0, 1}, {1, 0}, {1, 2}, {4, 3} };

        for(std::pair<int, int> pos : vecPos)
        {
            position.setX(pos.first);
            position.setY(pos.second);
            EXPECT_TRUE(position.isValid());
        }

        vecPos = { {-1, 0}, {0, -1}, {-1, -1}, {-2, -2}, {-4, -3} };

        for(std::pair<int, int> pos : vecPos)
        {
            position.setX(pos.first);
            position.setY(pos.second);
            EXPECT_FALSE(position.isValid());
        }
    }

}
