#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(multiply_3_fractions, examples)
{
    Fraction expected_output;

    expected_output = { 1, 16 };
    ASSERT_EQ(expected_output, multiply_3_fractions({ 1, 4 }, { 6, 8 }, { 2, 6 }));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}