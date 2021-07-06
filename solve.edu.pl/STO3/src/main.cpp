#include <bits/stdc++.h>
using namespace std;

const int MAX_CITIES = 1e6 + 1;
int graph[MAX_CITIES];

void add_connection(int city1, int city2)
{
    graph[city1]++;
    graph[city2]++;
}

int get_smallest_city(int cities = MAX_CITIES)
{
    size_t last_min_roads = graph[1];
    int last_min_index = 1;

    for (int i = 1; i <= cities; i++)
    {
        size_t size = graph[i];
        if (size < last_min_roads)
        {
            last_min_roads = size;
            last_min_index = i;
        }
    }

    return last_min_index;
}

void solve()
{
    int cities, roads;
    scanf("%d %d", &cities, &roads);

    for (int i = 0; i < roads; i++)
    {
        int city1, city2;
        scanf("%d %d", &city1, &city2);
        add_connection(city1, city2);
    }

    int smallest_city_idx = get_smallest_city(cities);
    int smallest_city_roads = graph[smallest_city_idx];
    printf("%d %d\n", smallest_city_idx, smallest_city_roads);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif