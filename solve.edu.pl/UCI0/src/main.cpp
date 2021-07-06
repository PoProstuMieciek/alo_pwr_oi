#include <stdio.h>
using namespace std;

const int MAX_SIZE = 1e3 + 2;
char maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool touched_exit = false;

bool is_on_board(int x, int y, int width, int height)
{
    return (x >= 0 && x < width) && (y >= 0 && y < height);
}

void dfs(int x, int y, int width, int height)
{
    if (!is_on_board(x, y, width, height)) return; // is outside maze
    if (visited[y][x]) return; // already visited
    if (maze[y][x] == 1) return; // wall

    if (maze[y][x] == 2) // exit
    {
        touched_exit = true;
        return;
    }

    visited[y][x] = true;

    dfs(x + 1, y, width, height);
    dfs(x - 1, y, width, height);
    dfs(x, y + 1, width, height);
    dfs(x, y - 1, width, height);
}

void solve()
{
    int height, width;
    scanf("%d %d", &height, &width);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            scanf("%d", (int*) &maze[y][x]);
        }
    }

    dfs(0, 0, width, height);

    printf(touched_exit ? "TAK\n" : "NIE\n");
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif