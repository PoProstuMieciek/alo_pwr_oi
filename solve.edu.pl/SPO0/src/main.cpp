#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 26 + 2;
pair<int, char> scores[MAX_N];

int main()
{
    int N;
    scanf("%i", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%i", &scores[i].first);
        scores[i].second = i + 'A';
    }

    sort(scores, scores + N + 1, [] (pair<int, char> a, pair<int, char> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    for (int i = 0; i < 3; i++)
    {
        printf("%c ", scores[i].second);
    }

    printf("\n");
}