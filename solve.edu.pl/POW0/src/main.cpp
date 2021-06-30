#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned int> items;

void solve()
{
    int queries; scanf("%i", &queries);
    for (int i = 0; i < queries; i++)
    {
        int numbers; scanf("%i", &numbers);
        for (int i = 0; i < numbers; i++)
        {
            int number; scanf("%i", &number);
            items.push_back(number);
        }

        sort(items.begin(), items.end());

        bool repeating = false;
        auto last_item = items[0];
        int combo = 1;
        for (size_t i = 1; i < items.size(); i++)
        {
            if (items[i] == last_item) combo++;
            else combo = 1;

            if (combo == 3)
            {
                repeating = true;
                break;
            }

            last_item = items[i];
        }

        printf(repeating ? "TAK\n" : "NIE\n");

        items.clear();
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif