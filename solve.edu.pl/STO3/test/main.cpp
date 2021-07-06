#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(get_smallest_city, examples)
{
    add_connection(1, 2);
    add_connection(1, 3);
    add_connection(2, 3);
    add_connection(4, 5);
    add_connection(4, 6);
    add_connection(3, 4);

    ASSERT_EQ(5, get_smallest_city(6));
    ASSERT_EQ(1, graph[5]);
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}