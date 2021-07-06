#include <bits/stdc++.h>
using namespace std;

const int MAX_GUESTS = 3e4 + 2;
vector<int> graph[MAX_GUESTS];
bool visited[MAX_GUESTS];
int steps = 0;

void dfs(int start)
{
    if (visited[start]) return;

    visited[start] = true;
    steps++;

    for (auto &&neighbor : graph[start])
    {
        dfs(neighbor);
    }
}

void add_connection(int left, int right)
{
    graph[right].push_back(left);
    // graph[left].push_back(right);
}

uint32_t get_tables(int guests = MAX_GUESTS)
{
    uint32_t tables = 0;
    for (int i = 1; i <= guests; i++)
    {
        steps = 0;
        dfs(i);
        if (steps > 0) tables++;
    }
    return tables;
}

void solve()
{
    int guests; scanf("%d", &guests);
    for (int i = 1; i <= guests; i++)
    {
        int left; scanf("%d", &left);
        add_connection(left, i);
    }

    printf("%d\n", get_tables(guests));
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif