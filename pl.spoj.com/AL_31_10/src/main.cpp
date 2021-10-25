#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

size_t count_char_in_str(const char *str, size_t size, char ch)
{
    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == ch) count++;
    }
    return count;
}

size_t find_max_idx(size_t *arr, size_t size)
{
    size_t last_max = 0;
    size_t last_max_idx = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > last_max)
        {
            last_max = arr[i];
            last_max_idx = i;
        }
    }
    return last_max_idx;
}

char get_special_letter(const char *str, size_t size)
{
    char *lower = (char *) malloc(size + 1);
    for(int i = 0; str[i]; i++) lower[i] = tolower(str[i]);

    size_t stats['z' - 'a' + 1];

    for (char i = 'a'; i <= 'z'; i++)
    {
        stats[i - 'a'] = count_char_in_str(lower, size, i);
    }

    // for (char i = 'a'; i <= 'z'; i++)
    // {
    //     printf("stats['%c'] = %ld\n", i, stats[i - 'a']);
    // }

    size_t stats_size = sizeof(stats) / sizeof(size_t);

    size_t max_1_idx = find_max_idx(stats, stats_size);
    size_t max_1_occ = stats[max_1_idx];
    stats[max_1_idx] = 0;

    size_t max_2_idx = find_max_idx(stats, stats_size);
    size_t max_2_occ = stats[max_2_idx];

    char max_1_ch = max_1_idx + 'a';
    char max_2_ch = max_2_idx + 'a';

    // printf("max_1 = %c (%ld), max_2 = %c (%ld)\n", max_1_ch, max_1_occ, max_2_ch, max_2_occ);

    if (max_1_occ > (2 * max_2_occ)) return max_1_ch;
    return 0;
}

void solve()
{
    char *line = NULL;
    size_t size = 0;
    ssize_t read = 0;

    for (int i = 1; (read = getdelim(&line, &size, '.', stdin)) != -1; i++)
    {
        line[--read] = 0;

        // printf("Received: '%s' (%ld)\n", line, read);

        char spec_char = get_special_letter(line, read);
        // printf("Special char: ");
        printf("%d - ", i);

        if (spec_char) printf("%c", spec_char);
        else printf("BRAK");

        printf("\n");
    }

    free(line);
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif