#include "pch.h"
#include "../src/Command/ReportCommandFactory.h"
#include "../src/Command/ReportCommand.h"

namespace ToyRobot
{
    TEST(ReportCommandFactoryTest, IsMatched)
    {
        std::unique_ptr<AbstractCommandFactory> reportCommandFactory = std::make_unique<ReportCommandFactory>();

        EXPECT_FALSE(reportCommandFactory->isMatched(""));
        EXPECT_FALSE(reportCommandFactory->isMatched("ABC"));
        EXPECT_FALSE(reportCommandFactory->isMatched("report"));

        EXPECT_TRUE(reportCommandFactory->isMatched("REPORT"));
    }

    TEST(ReportCommandFactoryTest, Build)
    {
        std::unique_ptr<AbstractCommandFactory> reportCommandFactory = std::make_unique<ReportCommandFactory>();

        EXPECT_EQ(reportCommandFactory->build(""), nullptr);
        EXPECT_EQ(reportCommandFactory->build("ABC"), nullptr);
        EXPECT_EQ(reportCommandFactory->build("report"), nullptr);

        EXPECT_NE(dynamic_cast<ReportCommand*>(reportCommandFactory->build("REPORT").get()), nullptr);
    }

}
