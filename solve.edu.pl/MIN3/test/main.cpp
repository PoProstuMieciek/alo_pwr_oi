#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(find_number, examples)
{
    ASSERT_EQ(8, find_number(2, { 1, 6 }));
    ASSERT_EQ(6, find_number(3, { 3, 5 }));
    ASSERT_EQ(3, find_number(3, { 4, 10 }));
    ASSERT_EQ(15, find_number(5, { 3, 14 }));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}