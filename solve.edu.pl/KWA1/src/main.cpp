#include <stdio.h>
using namespace std;

int main()
{
    int N;
    scanf("%i", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
}