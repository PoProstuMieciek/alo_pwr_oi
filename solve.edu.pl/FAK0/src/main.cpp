#include <bits/stdc++.h>
using namespace std;

const int MAX_VALUE = 8e6 + 10;
bool sieve[MAX_VALUE];

void build_sieve(int max_value = MAX_VALUE)
{
    for (int i = 2; i * i < max_value; i++)
    {
        if (!sieve[i])
        {
            for (int j = i * i; j < max_value; j+=i)
            {
                sieve[j] = true;
            }
        }
    }
}

vector<int> factorize(int number)
{
    if (!sieve[number]) return { number };

    vector<int> output;
    int current_divisor = 2;
    while (number != 1)
    {
        if (number % current_divisor == 0)
        {
            // printf("[DEBUG] Adding %d to the list\n", current_divisor);
            output.push_back(current_divisor);
            number /= current_divisor;
        }
        else
        {
            // printf("[DEBUG] Looking for next divisor...\n");
            do current_divisor++;
            while (sieve[current_divisor]);
            // printf("[DEBUG] Found next divisor %d\n", current_divisor);
        }
    }

    return output;
}

void solve()
{
    build_sieve();

    int queries; scanf("%d", &queries);
    for (int i = 0; i < queries; i++)
    {
        int number; scanf("%d", &number);

        auto factorized = factorize(number);
        for (size_t j = 0; j < factorized.size(); j++)
        {
            printf("%d ", factorized[j]);
        }
        printf("\n");
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif