#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Drop
{
    public:
        int position;
        int time;
};

bool get_rod_part(char *metal_rod, int part)
{
    int byte_idx = part / 8;
    int bit_idx = part % 8;

    char byte = metal_rod[byte_idx];

    return byte & (1 << bit_idx);
}

void set_rod_part(char *metal_rod, int part)
{
    int byte_idx = part / 8;
    int bit_idx = part % 8;

    metal_rod[byte_idx] |= 1 << bit_idx;
}

bool check_if_rod_all_covered(char *metal_rod, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!get_rod_part(metal_rod, i)) return false;
    }
    return true;
}

void print_rod(int current_time, char *metal_rod, int length)
{
    printf("%d: ", current_time);
    for (int i = 0; i < length; i++)
    {
        printf("%d", get_rod_part(metal_rod, i));
    }
    printf("\n");
}

int start(int length, Drop **acid_drops, int acid_drops_length)
{
    char *metal_rod = (char *) calloc((length / 8) + 1, 1);

    Drop *current_drop = acid_drops[0];
    int current_drop_index = 0;

    int current_time = 0;
    while (!check_if_rod_all_covered(metal_rod, length))
    {
        // print_rod(current_time, metal_rod, length);

        char *new_metal_rod = (char *) calloc((length / 8) + 1, 1);
        memcpy(new_metal_rod, metal_rod, (length / 8) + 1);

        for (int j = 0; j < length; j++)
        {
            if (get_rod_part(metal_rod, j))
            {
                int left_index = j - 1;
                int right_index = j + 1;

                if (left_index >= 0 && left_index < length)
                {
                    set_rod_part(new_metal_rod, left_index);
                }
                if (right_index >= 0 && right_index < length)
                {
                    set_rod_part(new_metal_rod, right_index);
                }
            }
        }
        free(metal_rod);
        metal_rod = new_metal_rod;

        // print_rod(current_time, metal_rod, length);

        while (current_drop->time == current_time)
        {
            set_rod_part(metal_rod, current_drop->position - 1);

            if (current_drop_index + 1 < acid_drops_length)
            {
                current_drop = acid_drops[++current_drop_index];
            }
            else break;
        }

        // print_rod(current_time, metal_rod, length);
        current_time++;
    }

    free(metal_rod);
    return current_time - 1;
}

void solve()
{
    int length, acid_drops_length;
    scanf("%d %d", &length, &acid_drops_length);

    Drop *acid_drops[acid_drops_length];

    for (int i = 0; i < acid_drops_length; i++)
    {
        acid_drops[i] = new Drop();

        scanf(
            "%d %d",
            &acid_drops[i]->position,
            &acid_drops[i]->time
        );
    }

    int result = start(length, acid_drops, acid_drops_length);
    printf("%d\n", result);

    for (int i = 0; i < acid_drops_length; i++)
    {
        delete acid_drops[i];
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif