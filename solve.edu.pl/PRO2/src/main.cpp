#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_NM = 1e3 + 2;
int ROWS, COLS, QUERIES;
ll prefix_sums[MAX_NM][MAX_NM];

struct Point
{
    int row, col;
};

struct Rect
{
    Point start, end;
};

void debug()
{
    for (int i = 0; i <= ROWS; i++)
    {
        for (int j = 0; j <= COLS; j++)
        {
            printf("%lli ", prefix_sums[i][j]);
        }
        printf("\n");
    }
}

ll rect_side_length_column(Rect& side)
{
    Point start = side.start, end = side.end;
    return prefix_sums[end.row][end.col] - prefix_sums[start.row][start.col - 1];
}

ll process_query(Rect& rect)
{
    int start = rect.start.row, end = rect.end.row;

    ll sum = 0;
    for (int i = start; i <= end; i++)
    {
        Rect piece;
        piece.start.row = i;
        piece.end.row = i;
        piece.start.col = rect.start.col;
        piece.end.col = rect.end.col;

        ll piece_length = rect_side_length_column(piece);
        sum += piece_length;
    }
    
    return sum;
}

int main()
{
    scanf("%i %i", &ROWS, &COLS);
    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= COLS; j++)
        {
            int tmp;
            scanf("%i", &tmp);

            prefix_sums[i][j] = prefix_sums[i][j-1] + tmp;
        }
    }

    scanf("%i", &QUERIES);
    for (int i = 0; i < QUERIES; i++)
    {
        Rect rect;
        
        scanf(
            "%i %i %i %i",
            &rect.start.row,
            &rect.start.col,
            &rect.end.row,
            &rect.end.col
        );

        printf("%lli\n", process_query(rect));
    }
}