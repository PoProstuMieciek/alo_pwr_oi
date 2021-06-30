#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(dec_to_bin, example)
{
    ASSERT_EQ("111", dec_to_bin(7));
    ASSERT_EQ("1010", dec_to_bin(10));
    ASSERT_EQ("10000", dec_to_bin(16));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}