#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef pair<int64_t, int64_t> Fraction;

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

int64_t lcm(int64_t a, int64_t b)
{
    return (a * b) / gcd(a, b);
}

Fraction expand_fraction(Fraction &a, int64_t denominator)
{
    int64_t multiply_by = denominator / a.second;
    a.first *= multiply_by;
    a.second *= multiply_by;
    return a;
}

void bring_to_common_denominator(Fraction &a, Fraction &b)
{
    if (a.second == b.second) return;

    int64_t common_denominator = lcm(a.second, b.second);
    expand_fraction(a, common_denominator);
    expand_fraction(b, common_denominator);
}

Fraction simplify_fraction(Fraction &input)
{
    int frac_gcd = gcd(input.first, input.second);
    input.first /= frac_gcd;
    input.second /= frac_gcd;
    return input;
}

Fraction add_fractions(Fraction a, Fraction b)
{
    Fraction result;

    bring_to_common_denominator(a, b);
    result.first = a.first + b.first;
    result.second = a.second;
    simplify_fraction(result);

    return result;
}

void solve()
{
    Fraction a, b;
    scanf("%lld %lld %lld %lld", &a.first, &a.second, &b.first, &b.second);
    
    Fraction result = add_fractions(a, b);
    printf("%lld %lld\n", result.first, result.second);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif