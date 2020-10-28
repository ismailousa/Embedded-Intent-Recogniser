#include <gtest/gtest.h>
#include <iostream>
#include "parser.hpp"

TEST(IntentTest, Parse) {
    EXPECT_TRUE(parser::parse("What is the weather like today?") == "Intent: Get Weather\n\n");
    EXPECT_TRUE(parser::parse("What is temperature tomorrow at 08:00 in Paris?") == "Intent: Get Weather City\n\n");
    EXPECT_TRUE(parser::parse("Can you tell me something interesting?") == "Intent: Get Fact\n\n");
    EXPECT_TRUE(parser::parse("Do I have something planned at 10:00 tomorrow?") == "Intent: Check Calendar\n\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "TESTS\n";
    return RUN_ALL_TESTS();
}