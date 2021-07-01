#include <bits/stdc++.h>
using namespace std;

char *time_format_12_to_24(char *input)
{
    int hours, minutes, seconds; char ap;
    sscanf(input, "%02d:%02d:%02d%cM", &hours, &minutes, &seconds, &ap);
    // printf("[DEBUG] hours=%i, minutes=%i, seconds=%i, ap=%c\n", hours, minutes, seconds, ap);

         if (ap == 'A' && hours == 12) hours -= 12;
    else if (ap == 'P' && hours != 12) hours += 12;

    char *output = (char *) malloc(16);
    sprintf(output, "%02d:%02d:%02d", hours, minutes, seconds);
    return output;
}

void solve()
{
    char input[16];
    scanf("%s", input);
    printf("%s\n", time_format_12_to_24(input));
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif