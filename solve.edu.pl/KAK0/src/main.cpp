#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 5e5 + 2;
int cactuses[MAX_N];
long long dp[MAX_N];

long long min_range(int range_start, int range_end)
{
    auto last_min = dp[range_start];

    for (int i = max(0, range_start); i < range_end; i++)
    {
        if (dp[i] < last_min) last_min = dp[i];
    }

    return last_min;
}

int main()
{
    int field_size, jump_size;
    scanf("%i %i", &field_size, &jump_size);

    for (int i = 0; i < field_size; i++)
    {
        scanf("%i", &cactuses[i]);
        dp[i] = 1e9+2;
    }

    for (int i = 0; i < jump_size; i++)
    {
        dp[i] = cactuses[i];
    }

    for (int i = jump_size; i < field_size; i++)
    {
        dp[i] = min_range(i - jump_size, i) + cactuses[i];
    }

    long long result = min_range(field_size - jump_size, field_size);
    printf("%lli\n", result);
}