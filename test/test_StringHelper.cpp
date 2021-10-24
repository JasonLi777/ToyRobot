#include "pch.h"
#include "..\src\Util\StringHelper.h"
#include <vector>

TEST(StringHelperTest, Split_Empty)
{    
    std::string str;
    std::vector<std::string> expected;

    EXPECT_EQ(expected, StringHelper::split(str, ""));
    EXPECT_EQ(expected, StringHelper::split(str, " "));
}

TEST(StringHelperTest, Split_Valid)
{
    std::string str = "123 abc efg";
    std::vector<std::string> expected1 = {"123", "abc", "efg"};
    std::vector<std::string> expected2 = { "123 ", "bc efg" };
    std::vector<std::string> expected3 = { "123 a", " efg" };

    EXPECT_EQ(expected1, StringHelper::split(str, " "));
    EXPECT_EQ(expected2, StringHelper::split(str, "a"));
    EXPECT_EQ(expected3, StringHelper::split(str, "bc"));
}

TEST(StringHelperTest, Split_LeadingAndRearMatch)
{
    std::string str = "  123 abc efg   ";
    std::vector<std::string> expected = {"123", "abc", "efg"};

    EXPECT_EQ(expected, StringHelper::split(str, " "));
}

TEST(StringHelperTest, ToUpper)
{
    std::string str = "  123 abc efg   ";
    std::string expected = "  123 ABC EFG   ";

    EXPECT_EQ(expected, StringHelper::toUpper(str));
}