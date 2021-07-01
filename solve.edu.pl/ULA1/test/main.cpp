#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(test_suite_name, test_name)
{
    Fraction expected_output;

    expected_output = { 2, 1 }; ASSERT_EQ(expected_output, add_fractions({ 3, 2 }, { 2, 4 }));
    expected_output = { 29, 36 }; ASSERT_EQ(expected_output, add_fractions({ 7, 18 }, { 5, 12 }));
    expected_output = { 4, 7 }; ASSERT_EQ(expected_output, add_fractions({ 1, 7 }, { 3, 7 }));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}