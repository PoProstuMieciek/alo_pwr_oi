#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(get_tables, examples)
{
    add_connection(4, 1);
    add_connection(10, 2);
    add_connection(7, 3);
    add_connection(3, 4);
    add_connection(2, 5);
    add_connection(6, 6);
    add_connection(1, 7);
    add_connection(5, 8);
    add_connection(11, 9);
    add_connection(8, 10);
    add_connection(12, 11);
    add_connection(9, 12);

    ASSERT_EQ(4, get_tables(12));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}