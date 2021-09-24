#include <stdio.h>
#include <stdlib.h>
using namespace std;

enum AntType
{
    ANT_BLACK = 1 << 0,
    ANT_RED   = 1 << 1,
    ANT_ANY   = ANT_BLACK | ANT_RED 
};

struct Bounds
{
    int min_x = __INT32_MAX__;
    int max_x = -1;
    int min_y = __INT32_MAX__;
    int max_y = -1;

    Bounds() {}
    Bounds(int min_x, int max_x, int min_y, int max_y): min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y) {}
};

bool operator==(const Bounds& l, const Bounds& r)
{
    if (l.min_x != r.min_x) return false;
    if (l.max_x != r.max_x) return false;
    if (l.min_y != r.min_y) return false;
    if (l.max_y != r.max_y) return false;
    return true;
}

struct Coordinates
{
    int x;
    int y;

    bool is_inside_bounds(Bounds bounds)
    {
        bool ok = true;
        ok &= (bounds.min_x <= this->x && this->x <= bounds.max_x);
        ok &= (bounds.min_y <= this->y && this->y <= bounds.max_y);
        return ok;
    }
};

struct Ant
{
    Coordinates position;
    AntType type;
};

Bounds get_ant_bounds(Ant *ants, size_t ants_size, AntType ant_type)
{
    Bounds bounds = {};

    for (size_t i = 0; i < ants_size; i++)
    {
        Ant ant = ants[i];

        if (!(ant.type & ant_type)) continue;

        if (ant.position.x <= bounds.min_x) bounds.min_x = ant.position.x;
        if (ant.position.x > bounds.max_x) bounds.max_x = ant.position.x;
        if (ant.position.y <= bounds.min_y) bounds.min_y = ant.position.y;
        if (ant.position.y > bounds.max_y) bounds.max_y = ant.position.y;
    }

    return bounds;
}

size_t count_in_bounds(Ant *ants, size_t ants_size, AntType ant_type, Bounds bounds)
{
    size_t count = 0;

    for (size_t i = 0; i < ants_size; i++)
    {
        Ant ant = ants[i];

        if (!(ant.type & ant_type)) continue;

        count += ant.position.is_inside_bounds(bounds);
    }

    return count;
}

void solve()
{
    int datasets;
    scanf("%d", &datasets);

    for (int d = 0; d < datasets; d++)
    {
        int ants_size;
        scanf("%d", &ants_size);

        Ant *ants = (Ant *) malloc(ants_size * sizeof(Ant));
        for (int a = 0; a < ants_size; a++)
        {
            ants[a] = {};
            Ant *ant = &ants[a];
            int ant_type;

            scanf
            (
                "%d %d %d",
                &ant->position.x,
                &ant->position.y,
                &ant_type
            );

            if (ant_type == 0) ant->type = ANT_BLACK;
            if (ant_type == 1) ant->type = ANT_RED;
        }

        Bounds bounds = get_ant_bounds(ants, ants_size, ANT_RED);
        size_t count = count_in_bounds(ants, ants_size, ANT_ANY, bounds);
        free(ants);

        printf("%ld\n", count);
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif