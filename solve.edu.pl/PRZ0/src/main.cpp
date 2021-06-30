#include <stdio.h>
using namespace std;

bool is_leap_year(int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

void solve()
{
    int n; scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        int year; scanf("%i", &year);
        printf(is_leap_year(year) ? "TAK\n" : "NIE\n");
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif