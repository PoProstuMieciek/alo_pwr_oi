#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int total_numbers;
    scanf("%i", &total_numbers);

    long long best_sum = 0;
    long long current_sum = 0;
    for (int i = 0; i < total_numbers; i++)
    {
        int number;
        scanf("%i", &number);

        current_sum = max((long long) 0, current_sum + number);
        best_sum = max(best_sum, current_sum);
    }

    printf("%lli\n", best_sum);
}