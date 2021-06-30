#include <bits/stdc++.h>
#include <string>
using namespace std;

int digit_add(char a, char b, int carry = 0)
{
    a -= '0'; b -= '0';
    return a + b + carry;
}

string bignum_add(string a, string b)
{
    if (a.size() != b.size()) return nullptr;

    string output = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int sum = digit_add(a[i], b[i], carry);
        carry = sum / 10;

        char char_to_add = sum % 10 + '0';
        output = char_to_add + output;
    }
    if (carry > 0) output = to_string(carry) + output;

    return output;
}

// modifies input and also returns modified input
string pad_string(string &input, size_t length, char fill_char, bool front = false)
{
    int delta = abs((int) input.size() - (int) length);

    if (input.size() > length)
    {
        if (front) input.erase(0, delta);
        else input.erase(input.size() - delta, delta);
    }
    else if (input.size() < length)
    {
        for (int i = 0; i < delta; i++)
        {
            if (front) input = fill_char + input;
            else input += fill_char;
        }
    }

    return input;
}

void solve()
{
    string a, b;
    cin >> a >> b;

    auto pad_to = max(a.size(), b.size());
    pad_string(a, pad_to, '0', true);
    pad_string(b, pad_to, '0', true);

    // printf("a: %s\nb: %s\n", a.c_str(), b.c_str());

    printf("%s\n", bignum_add(a, b).c_str());
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif