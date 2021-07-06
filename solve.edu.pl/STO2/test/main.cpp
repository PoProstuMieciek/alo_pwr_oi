#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(get_largest_city, examples)
{
    add_connection(1, 2);
    add_connection(1, 3);
    add_connection(2, 3);
    add_connection(4, 5);
    add_connection(4, 6);
    add_connection(3, 4);

    ASSERT_EQ(3, get_largest_city(6));
    ASSERT_EQ(3, graph[3]);
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}