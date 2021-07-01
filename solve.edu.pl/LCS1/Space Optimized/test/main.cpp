#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(lcs_length, examples)
{
    ASSERT_EQ(6, lcs_length("deskorolka", "stokrotka"));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}