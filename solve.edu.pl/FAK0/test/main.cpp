#define GTEST_DECLARES_MAIN

#include "../src/main.cpp"
#include <gtest/gtest.h>
#include <sys/time.h>
using namespace std;
using namespace testing;

TEST(factorize, examples)
{
    build_sieve();

    vector<int> expected_output;

    expected_output = { 1 }; ASSERT_EQ(expected_output, factorize(1));
    expected_output = { 2 }; ASSERT_EQ(expected_output, factorize(2));
    expected_output = { 2, 3, 7 }; ASSERT_EQ(expected_output, factorize(42));
    expected_output = { 2, 157 }; ASSERT_EQ(expected_output, factorize(314));
    expected_output = { 7, 199, 5743 }; ASSERT_EQ(expected_output, factorize(7999999));
    expected_output = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5 }; ASSERT_EQ(expected_output, factorize(8000000));
}

TEST(factorize, random)
{
    struct timeval time; 
    gettimeofday(&time, NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));

    for (int i = 0; i < 3000; i++)
    {
        int number = rand() % MAX_VALUE + 1;
        auto factorized = factorize(number);

        int expected_output = 1;
        for (size_t j = 0; j < factorized.size(); j++)
        {
            expected_output *= factorized[j];
        }

        ASSERT_EQ(expected_output, number);
    }
}

int main(int argc, char *argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}