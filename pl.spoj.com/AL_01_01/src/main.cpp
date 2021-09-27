#include <stdio.h>
#include <algorithm>
using namespace std;

bool find_sum(int *choices_a, int *choices_b, size_t choices, int target_sum)
{
    for (size_t a = 0; a < choices; a++)
    {
        if (choices_a[a] >= target_sum) break;

        for (size_t b = 0; b < choices; b++)
        {
            if (choices_b[b] >= target_sum) continue;

            if (choices_a[a] + choices_b[b] == target_sum) return true;
        }
    }

    return false;
}

bool sort_descending(int a, int b)
{
    return a > b;
}

bool sort_ascending(int a, int b)
{
    return a < b;
}

void solve()
{
    int choices, queries;
    scanf("%d %d", &choices, &queries);

    int *choices_a = (int *) malloc(choices * sizeof(int));
    int *choices_b = (int *) malloc(choices * sizeof(int));

    for (int i = 0; i < choices; i++)
    {
        scanf("%d", &choices_a[i]);
    }
    for (int i = 0; i < choices; i++)
    {
        scanf("%d", &choices_b[i]);
    }

    // sort(choices_a, choices_a + choices, sort_descending);
    // sort(choices_b, choices_b + choices, sort_descending);

    sort(choices_a, choices_a + choices, sort_ascending);
    sort(choices_b, choices_b + choices, sort_descending);

    for (int i = 0; i < queries; i++)
    {
        int target;
        scanf("%d", &target);

        bool answer = find_sum(choices_a, choices_b, choices, target);

        printf("%s\n", answer ? "TAK" : "NIE");
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif