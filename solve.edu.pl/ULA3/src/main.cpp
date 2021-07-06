#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Fraction;

int64_t gcd(int64_t a, int64_t b)
{
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;

    if (a & 1)
    {
        if (b % 2 == 0) return gcd(a, b / 2);
        if (a > b) return gcd((a - b) / 2, b);
        else return gcd((b - a) / 2, a);
    }
    else
    {
        if (b & 1) return gcd(a / 2, b);
        else return 2 * gcd(a / 2, b / 2);
    }
}

Fraction simplify_fraction(Fraction &input)
{
    int frac_gcd = gcd(input.first, input.second);
    input.first /= frac_gcd;
    input.second /= frac_gcd;
    return input;
}

Fraction period_to_fraction(const char *period)
{
    Fraction periodic;
    periodic.first = atoi(period);
    periodic.second = pow(10, strlen(period)) - 1;

    simplify_fraction(periodic);
    return periodic;
}

void solve()
{
    char period[9];
    scanf("%s", period);

    auto fraction = period_to_fraction(period);
    printf("%d/%d\n", fraction.first, fraction.second);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif