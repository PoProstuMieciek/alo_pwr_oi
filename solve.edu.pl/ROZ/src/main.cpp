#include <bits/stdc++.h>
using namespace std;

const int MAX_CITIES = 1e5 + 2;
vector<pair<int, int>> roads;
vector<int> graph[MAX_CITIES];
bool visited[MAX_CITIES];
int steps = 0;

void clean_visited(int total_cities = MAX_CITIES)
{
    for (int i = 1; i <= total_cities; i++)
    {
        visited[i] = false;
    }
    steps = 0;
}

void dfs(int start)
{
    if (visited[start]) return;
    visited[start] = true;
    steps++;

    for (int city : graph[start])
    {
        // if city is no longer available
        // if city was already visited, do not even put dfs() call on stack
        if (!visited[city] && city != 0)
        {
            dfs(city);
        }
    }
}

void close_road(int road_index)
{
    auto road = roads[road_index];
    int from = road.first, to = road.second;

    for (size_t i = 0; i < graph[from].size(); i++)
    {
        if (graph[from][i] == to)
        {
            graph[from][i] = 0;
            break;
        }
    }
    for (size_t i = 0; i < graph[to].size(); i++)
    {
        if (graph[to][i] == from)
        {
            graph[to][i] = 0;
            break;
        }
    }
}

int districts(int total_cities = MAX_CITIES)
{
    int total_districts = 0;

    for (int i = 1; i <= total_cities; i++)
    {
        steps = 0;
        dfs(i);

        if (steps > 0) total_districts++;
    }

    return total_districts;
}

int main()
{
    int total_cities, total_roads;
    scanf("%i %i", &total_cities, &total_roads);
    for (int i = 0; i < total_roads; i++)
    {
        int city1, city2;
        scanf("%i %i", &city1, &city2);

        graph[city1].push_back(city2);
        graph[city2].push_back(city1);
        roads.push_back({ city1, city2 });
    }

    int closed_roads;
    scanf("%i", &closed_roads);
    for (int i = 0; i < closed_roads; i++)
    {
        clean_visited(total_cities);

        int closed_road_index;
        scanf("%i", &closed_road_index);

        close_road(closed_road_index - 1);
        printf("%i ", districts(total_cities));
    }

    printf("\n");
}