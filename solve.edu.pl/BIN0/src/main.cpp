#include <stdio.h>
#include <string>
using namespace std;

string dec_to_bin(long long decimal_input)
{
    if (decimal_input == 0) return "0";

    string output = "";
    while (decimal_input != 0)
    {
        char add = decimal_input % 2 + '0';
        output = add + output;
        decimal_input >>= 1;
    }
    return output;
}

void solve()
{
    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        long long number;
        scanf("%lli", &number);
        printf("%s\n", dec_to_bin(number).c_str());
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif