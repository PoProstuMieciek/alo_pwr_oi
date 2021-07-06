#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(test_suite_name, test_name)
{
    internal::CaptureStdout();

    process_query(PUSH, 1);
    process_query(PUSH, 9);
    process_query(FRONT);
    process_query(POP);
    process_query(PUSH, 5);
    process_query(PUSH, 7);
    process_query(FRONT);

    ASSERT_EQ("1\n9\n", internal::GetCapturedStdout());
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}