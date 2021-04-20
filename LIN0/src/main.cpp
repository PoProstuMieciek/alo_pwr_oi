#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6 + 2;
int input[MAX_N];
long long vals[MAX_N];
int n;

int main()
{
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &input[i]);
        vals[i] = 1e9 + 2;
    }

    vals[0] = input[0];
    vals[1] = input[1];

    for (int i = 2; i < n; i++)
    {
        // vals[i] = min(vals[i-1] + input[i], vals[i-2] + input[i]);
        vals[i] = min(vals[i-1], vals[i-2]) + input[i];
    }

    long long result = min(vals[n-1], vals[n-2]);
    printf("%lli\n", result);
}