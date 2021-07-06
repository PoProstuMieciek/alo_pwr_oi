#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(period_to_fraction, examples)
{
    Fraction expected_output = { 1, 3 };
    ASSERT_EQ(expected_output, period_to_fraction("33"));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}