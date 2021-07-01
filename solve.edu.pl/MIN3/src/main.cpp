#include <bits/stdc++.h>
using namespace std;

typedef pair<uint64_t, uint64_t> Range;

bool is_in_range(uint64_t check, Range range)
{
    return range.first <= check && check <= range.second;
}

uint64_t find_number(uint64_t divisor, Range excluded_range)
{
    // printf("find_number(%ld, { %ld, %ld })\n", divisor, excluded_range.first, excluded_range.second);

    uint64_t check = 1;
    while (true)
    {
        // printf("[DEBUG] check=%ld\n", check);

        if (is_in_range(check, excluded_range))
        {
            // printf("[DEBUG] going outside exluded range (%ld -> %ld)\n", check, excluded_range.second + 1);
            check = excluded_range.second + 1;
            continue;
        }
        else
        {
            if (check % divisor == 0)
            {
                // printf("[DEBUG] found answer %ld\n", check);
                break;
            }
            else
            {
                // printf("[DEBUG] skipping (%ld -> %ld)\n", check, check - (check % divisor) + divisor);
                check = check - (check % divisor) + divisor;
            }
        }
    }

    return check;
}

void solve()
{
    int queries; scanf("%d", &queries);
    for (int i = 0; i < queries; i++)
    {
        uint64_t divisor; Range excluded_range;
        scanf("%" SCNu64 " %" SCNu64 " %" SCNu64, &divisor, &excluded_range.first, &excluded_range.second);
        printf("%" SCNu64 "\n", find_number(divisor, excluded_range));
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif