#include <bits/stdc++.h>
using namespace std;

const int MAX_VALUES = 2e5 + 2;
const int MAX_NODES = 10e5 + 2;
int values[MAX_VALUES];

// source: https://stackoverflow.com/a/466242/12126676
long long closestPower(int a)
{
    a--;
    a |= a >> 1;
    a |= a >> 2;
    a |= a >> 4;
    a |= a >> 8;
    a |= a >> 16;
    a++;

    return a;
}

enum QueryType
{
    UPDATE = 1,
    SUM = 2
};

class Node
{
    public:
        long long value;

        int index;

        int range_left;
        int range_right;
};

Node *nodes[MAX_NODES];

Node *buildTree(int range_left, int range_right, int index = 1)
{
    nodes[index] = new Node();

    Node *node = nodes[index];
    node->index = index;
    node->range_left = range_left;
    node->range_right = range_right;

    if (range_left == range_right)
    {
        node->value = values[range_left];
    }
    else
    {
        int range_middle = (range_left + range_right) / 2;
        nodes[2 * index] = buildTree(range_left, range_middle, 2 * index);
        nodes[2 * index + 1] = buildTree(range_middle + 1, range_right, 2 * index + 1);

        node->value = nodes[2 * index]->value + nodes[2 * index + 1]->value;
    }

    return node;
}

void updateNode(int node_index, int total_items, long long value)
{
    auto node_value_index = closestPower(total_items) + node_index - 1;
    Node *node = nodes[node_value_index];
    auto delta = value - node->value;

    int current_node_index = node_value_index;
    while (current_node_index > 0)
    {
        node = nodes[current_node_index];
        node->value += delta;

        current_node_index /= 2;
    }

    // printf("root value: %lli\n", nodes[1]->value);
}

long long getSum(int range_left, int range_right, Node *current_node)
{
    if (current_node->range_left == range_left && current_node->range_right == range_right)
    {
        return current_node->value;
    }
    else
    {
        if (range_left > range_right) return 0;

        auto left_child = nodes[2 * current_node->index];
        auto right_child = nodes[2 * current_node->index + 1];

        auto left_sum  = getSum(
            range_left,
            min(range_right, left_child->range_right),
            nodes[2 * current_node->index]
        );
        auto right_sum = getSum(
            max(right_child->range_left, range_left),
            range_right,
            nodes[2 * current_node->index + 1]
        );

        return left_sum + right_sum;
    }
}

int main()
{
    int numbers, queries;
    scanf("%i %i", &numbers, &queries);

    for (int i = 1; i <= numbers; i++)
    {
        scanf("%i", &values[i]);
    }

    buildTree(1, closestPower(numbers));

    for (int i = 0; i < queries; i++)
    {
        int query_type, arg1, arg2;

        scanf("%i %i %i", &query_type, &arg1, &arg2);

        // printf("query: %i %i %i\n", query_type, arg1, arg2);

        if (query_type == UPDATE)
        {
            // position = arg1
            // value = arg2

            updateNode(arg1, numbers, arg2);
        }
        else if (query_type == SUM)
        {
            // range [arg1, arg2]

            printf("%lli\n", getSum(arg1, arg2, nodes[1]));
        }
    }

    printf("\n");
}