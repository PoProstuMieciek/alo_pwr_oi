#include <bits/stdc++.h>
using namespace std;

const int MAX_CITIES = 1e5 + 2;
const int MAX_ROADS = 2e5 + 2;
int districts[MAX_CITIES]; // for every city keep its district index
vector<int> dist_members[MAX_CITIES]; // for every district keep its members
int total_districts = 0;

vector<pair<int, int>> roads;

void setup_cities(int total_cities = MAX_CITIES)
{
    for (int i = 1; i <= total_cities; i++)
    {
        districts[i] = i;
        dist_members[i].push_back(i);
    }
    total_districts = total_cities;
}

void merge_cities(int city1_idx, int city2_idx)
{
    if (districts[city1_idx] != districts[city2_idx]) total_districts--;
    else return;

    int dist1 = districts[city1_idx], dist2 = districts[city2_idx];
    int smaller = dist1, larger = dist2;

    if (dist_members[dist1].size() > dist_members[dist2].size())
    {
        larger = dist1;
        smaller = dist2;
    }

    dist_members[larger].insert(
        dist_members[larger].end(),
        dist_members[smaller].begin(),
        dist_members[smaller].end()
    );

    for (size_t i = 0; i < dist_members[smaller].size(); i++)
    {
        districts[dist_members[smaller][i]] = larger;
    }
}

int main()
{
    int total_cities, total_roads;
    scanf("%i %i", &total_cities, &total_roads);
    for (int i = 0; i < total_roads; i++)
    {
        int city1, city2;
        scanf("%i %i", &city1, &city2);
        roads.push_back({ city1, city2 });
    }

    setup_cities(total_cities);

    for (int i = 0; i < total_roads; i++)
    {
        auto road = roads[i];

        merge_cities(road.first, road.second);

        printf("%i\n", total_districts);
    }

    printf("\n");
}