#include <stdio.h>
#include <stdlib.h>
using namespace std;

size_t get_longest_arithmetic_sequence_length(int *numbers, size_t size)
{
    int *deltas = (int *) malloc((size + 1) * sizeof(int));

    for (size_t i = 1; i < size; i++)
    {
        deltas[i] = numbers[i] - numbers[i - 1];

        // printf("deltas[%ld] = numbers[%ld] - numbers[%ld] = %d\n", i, i, i - 1, deltas[i]);
    }

    int last_delta = deltas[1];
    int last_deltas_size = 1;
    int max_size = 1;
    for (size_t i = 2; i < size; i++)
    {
        int curr_delta = deltas[i];

        if (curr_delta == last_delta)
        {
            last_deltas_size++;
        }
        else
        {
            if (last_deltas_size > max_size)
            {
                max_size = last_deltas_size;
            }
            last_deltas_size = 1;
        }

        last_delta = curr_delta;
    }

    if (last_deltas_size > max_size)
    {
        max_size = last_deltas_size;
    }

    return max_size + 1;
}

void test()
{
    int size;
    scanf("%d", &size);

    int *numbers = (int *) malloc((size + 1) * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }

    size_t result = get_longest_arithmetic_sequence_length(numbers, size);
    printf("%ld\n", result);
}

void solve()
{
    int tests;
    scanf("%d", &tests);

    for (int i = 0; i < tests; i++)
    {
        test();
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif