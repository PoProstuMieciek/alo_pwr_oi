#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef pair<int, int> Fraction;

uint32_t gcd(uint32_t a, uint32_t b)
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

Fraction multiply_3_fractions(Fraction a, Fraction b, Fraction c)
{
    Fraction result;
    result.first = a.first * b.first * c.first;
    result.second = a.second * b.second * c.second;
    simplify_fraction(result);

    return result;
}

void solve()
{
    Fraction a, b, c;
    scanf("%d %d %d %d %d %d", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second);
    
    Fraction result = multiply_3_fractions(a, b, c);
    printf("%d/%d\n", result.first, result.second);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif