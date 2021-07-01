#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

TEST(time_format_12_to_24, hours_from_1_to_12)
{
    ASSERT_STREQ("01:00:00", time_format_12_to_24("01:00:00AM"));
    ASSERT_STREQ("02:00:00", time_format_12_to_24("02:00:00AM"));
    ASSERT_STREQ("03:00:00", time_format_12_to_24("03:00:00AM"));
    ASSERT_STREQ("04:00:00", time_format_12_to_24("04:00:00AM"));
    ASSERT_STREQ("05:00:00", time_format_12_to_24("05:00:00AM"));
    ASSERT_STREQ("06:00:00", time_format_12_to_24("06:00:00AM"));
    ASSERT_STREQ("07:00:00", time_format_12_to_24("07:00:00AM"));
    ASSERT_STREQ("08:00:00", time_format_12_to_24("08:00:00AM"));
    ASSERT_STREQ("09:00:00", time_format_12_to_24("09:00:00AM"));
    ASSERT_STREQ("10:00:00", time_format_12_to_24("10:00:00AM"));
    ASSERT_STREQ("11:00:00", time_format_12_to_24("11:00:00AM"));
    ASSERT_STREQ("00:00:00", time_format_12_to_24("12:00:00AM"));

    ASSERT_STREQ("13:00:00", time_format_12_to_24("01:00:00PM"));
    ASSERT_STREQ("14:00:00", time_format_12_to_24("02:00:00PM"));
    ASSERT_STREQ("15:00:00", time_format_12_to_24("03:00:00PM"));
    ASSERT_STREQ("16:00:00", time_format_12_to_24("04:00:00PM"));
    ASSERT_STREQ("17:00:00", time_format_12_to_24("05:00:00PM"));
    ASSERT_STREQ("18:00:00", time_format_12_to_24("06:00:00PM"));
    ASSERT_STREQ("19:00:00", time_format_12_to_24("07:00:00PM"));
    ASSERT_STREQ("20:00:00", time_format_12_to_24("08:00:00PM"));
    ASSERT_STREQ("21:00:00", time_format_12_to_24("09:00:00PM"));
    ASSERT_STREQ("22:00:00", time_format_12_to_24("10:00:00PM"));
    ASSERT_STREQ("23:00:00", time_format_12_to_24("11:00:00PM"));
    ASSERT_STREQ("12:00:00", time_format_12_to_24("12:00:00PM"));
}

TEST(time_format_12_to_24, examples)
{
    ASSERT_STREQ("19:05:45", time_format_12_to_24("07:05:45PM"));
    ASSERT_STREQ("00:00:00", time_format_12_to_24("12:00:00AM"));
    ASSERT_STREQ("08:01:32", time_format_12_to_24("08:01:32AM"));
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}