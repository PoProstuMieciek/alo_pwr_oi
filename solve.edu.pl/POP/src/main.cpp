#include <bits/stdc++.h>
using namespace std;

queue<int> q;

enum QueryType
{
    POP,
    PUSH,
    FRONT
};

void process_query(QueryType type, int arg = 0)
{
    if ((type == POP || type == FRONT) && q.empty())
    {
        printf("PUSTA KOLEJKA\n");
        return;
    }

    switch (type)
    {
        case POP:
            q.pop();
        break;

        case PUSH:
            q.push(arg);
        break;

        case FRONT:
            printf("%d\n", q.front());
        break;
    }
}

void solve()
{
    int queries; scanf("%d", &queries);
    for (int i = 0; i < queries; i++)
    {
        QueryType type; int arg = 0;

        scanf("%d", (int*) &type);
        if (type == PUSH) scanf("%d", &arg);

        process_query(type, arg);
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif