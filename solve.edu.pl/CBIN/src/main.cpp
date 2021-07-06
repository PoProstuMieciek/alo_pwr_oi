#include <bits/stdc++.h>
using namespace std;

string get_path(long long number)
{
    string output = "";

    while (number != 1)
    {
        output += (number % 2 == 0) ? 'L' : 'P';
        number -= number % 2;
        number /= 2;
    }

    reverse(output.begin(), output.end());
    return output;
}

void solve()
{
    long long number;
    scanf("%lld", &number);
    printf("%s\n", get_path(number).c_str());
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif