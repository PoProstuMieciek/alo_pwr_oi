#include <bits/stdc++.h>
using namespace std;

const int MAX_LENGTH = 5e3 + 2;

int lcs_length(char *word_a, char *word_b, size_t size_a = 0, size_t size_b = 0)
{
    if (size_a == 0) size_a = strlen(word_a);
    if (size_b == 0) size_b = strlen(word_b);

    unsigned int lcs[2][size_b + 1];
    bool bi; // binary index

    for (size_t i = 0; i <= size_a; i++)
    {
        bi = i & 1;

        for (size_t j = 0; j <= size_b; j++)
        {
            if (i == 0 || j == 0) lcs[bi][j] = 0;
            else if (word_a[i - 1] == word_b[j - 1]) lcs[bi][j] = lcs[1 - bi][j - 1] + 1;
            else lcs[bi][j] = max(lcs[1 - bi][j], lcs[bi][j - 1]);
        }
    }

    return lcs[bi][size_b];
}

void solve()
{
    char a[MAX_LENGTH], b[MAX_LENGTH];
    scanf("%s %s", a, b);
    // printf("[DEBUG] a=%s; b=%s;\n", a, b);

    printf("%d\n", lcs_length(a, b));
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif