#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
using namespace std;

struct Ant
{
    int position;
    int speed;

    Ant() {}
    Ant(int position, int speed) : position(position), speed(speed) {}
};

size_t get_ant_columns(Ant *ants, size_t ants_size)
{
    if (ants_size <= 1) return ants_size;

    Ant *current_ant = &ants[ants_size - 1];
    size_t count = 1;

    for (int i = ants_size - 2; i >= 0; i--)
    {
        Ant *ant = &ants[i];

        // if (ant->speed == current_ant->speed && current_ant->position - ant->position == 1)
        // {
        //     current_ant = ant;
        //     continue;
        // }

        if (ant->speed <= current_ant->speed)
        {
            count++;
            current_ant = ant;
        }
    }

    return count;
}

void solve()
{
    int ants_size;
    scanf("%d", &ants_size);

    Ant *ants = (Ant *) malloc(ants_size * sizeof(Ant));
    for (int a = 0; a < ants_size; a++)
    {
        ants[a] = {};
        Ant *ant = &ants[a];

        scanf
        (
            "%d %d",
            &ant->position,
            &ant->speed
        );
    }

    size_t columns = get_ant_columns(ants, ants_size);
    free(ants);

    printf("%ld\n", columns);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif