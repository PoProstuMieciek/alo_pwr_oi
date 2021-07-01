#include <bits/stdc++.h>
using namespace std;

string base10_to_base3(long long input)
{
    string output;
    while (input > 0)
    {
        output = (char) (input % 3 + '0') + output;
        input /= 3;
    }
    return output;
}

void solve()
{
    long long base10;
    scanf("%lld", &base10);

    string base3 = base10_to_base3(base10);

    long long stats[3] = { 0, 0, 0 };
    for (size_t i = 0; i < base3.size(); i++)
    {
        stats[base3[i] - '0']++;
    }

    printf("%lld %lld %lld\n", stats[0], stats[1], stats[2]);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif