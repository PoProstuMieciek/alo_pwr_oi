#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(get_ant_bounds, example)
{
    Ant ants[] =
    {
        { { 6, 3 }, ANT_RED },
        { { 1, 2 }, ANT_BLACK },
        { { 7, 2 }, ANT_BLACK },
        { { 5, 1 }, ANT_RED },
        { { 2, 5 }, ANT_BLACK },
        { { 4, 4 }, ANT_BLACK },
        { { 1, 4 }, ANT_RED },
        { { 3, 3 }, ANT_BLACK },
        { { 5, 7 }, ANT_BLACK }
    };

    Bounds expected = { 1, 6, 1, 4 };
    Bounds bounds = get_ant_bounds(ants, 9, ANT_RED);
    ASSERT_EQ(expected, bounds);

    size_t black_ants = count_in_bounds(ants, 9, ANT_BLACK, bounds);
    ASSERT_EQ(3, black_ants);

    size_t red_ants = count_in_bounds(ants, 9, ANT_RED, bounds);
    ASSERT_EQ(3, red_ants);

    size_t all_ants = count_in_bounds(ants, 9, ANT_ANY, bounds);
    ASSERT_EQ(6, all_ants);
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}