#include <stdio.h>
using namespace std;

const int MAX_N = 1e3 + 1;
bool board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int steps = 0;

bool is_on_board(int x, int y, int size)
{
    return (x >= 0 && x < size) && (y >= 0 && y < size);
}

void dfs(int x, int y, int size)
{
    if (!is_on_board(x, y, size)) return; // is not in range of our board
    if (visited[y][x]) return; // already visited
    if (!board[y][x]) return; // not land

    visited[y][x] = true;
    steps++;

    dfs(x + 1, y, size);
    dfs(x - 1, y, size);
    dfs(x, y + 1, size);
    dfs(x, y - 1, size);
}

void solve()
{
    int size; scanf("%i", &size);
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            int tmp; scanf("%i", &tmp);
            board[y][x] = (tmp == 1);
        }
    }

    int total_islands = 0;
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            steps = 0;
            dfs(x, y, size);
            if (steps > 0) total_islands++;
        }
    }

    printf("%i\n", total_islands);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif