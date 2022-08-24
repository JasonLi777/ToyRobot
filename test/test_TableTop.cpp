#include "pch.h"
#include "../src/TableTop/TableTop.h"

namespace ToyRobot
{

    TEST(TableTopTest, Init_WithValidValue)
    {
        int width = 1;
        int length = 2;
        TableTop tableTop = TableTop(width, length);

        EXPECT_EQ(tableTop.getWidth(), width);
        EXPECT_EQ(tableTop.getLength(), length);
    }

    TEST(TableTopTest, Init_WithInvalidValue)
    {
        int width = -1;
        int length = -2;
        TableTop tableTop = TableTop(width, length);

        EXPECT_EQ(tableTop.getWidth(), width);
        EXPECT_EQ(tableTop.getLength(), length);
    }

    TEST(TableTopTest, IsValid_Valid)
    {
        std::vector<std::pair<int, int>> vecRect = { {1, 1}, {1, 2}, {4, 2} };

        for(const auto& rect : vecRect)
        {
            TableTop tableTop = TableTop(rect.first, rect.second);
            EXPECT_TRUE(tableTop.isValid());
        }
    }

    TEST(TableTopTest, Isvalid_Invalid)
    {
        std::vector<std::pair<int, int>> vecRect = { {0, 0}, {0, 1}, {1, 0}, {-1, -2}, {-4, -3} };

        for(const auto& rect : vecRect)
        {
            TableTop tableTop = TableTop(rect.first, rect.second);
            EXPECT_FALSE(tableTop.isValid());
        }
    }

    TEST(TableTopTest, IsOnTheTable_TableInvalid)
    {
        TableTop tableTop = TableTop(0, 0);
        EXPECT_FALSE(tableTop.isOnTheTable(1, 2));
    }

    TEST(TableTopTest, IsOnTheTable_OnTheTable)
    {
        TableTop tableTop = TableTop(5, 5);

        std::vector<std::pair<int, int>> vecPos = { {0, 0}, {0, 1}, {1, 0}, {2, 2}, {0, 4}, {4, 0}, {4, 4} };

        for(std::pair<int, int> pos : vecPos)
        {
            EXPECT_TRUE(tableTop.isOnTheTable(pos.first, pos.second));
        }
    }

    TEST(TableTopTest, IsOnTheTable_NotOnTheTable)
    {
        TableTop tableTop = TableTop(5, 5);

        std::vector<std::pair<int, int>> vecPos = { {-1, -1}, {0, -1}, {-1, 0}, {5, 0}, {0, 5}, {5, 5}, {6, 7} };

        for(std::pair<int, int> pos : vecPos)
        {
            EXPECT_FALSE(tableTop.isOnTheTable(pos.first, pos.second));
        }
    }

}
