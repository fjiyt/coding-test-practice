#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[1001][3] = {{
    0,
}};

int choice[1001] = {
    0,
};

int N;
int min_cost = 1000001;

int solve(int x, int sum)
{
    int pre_index = choice[x - 1];
    int first_index = choice[0];
    int min_sum = 1000001;

    if (x == N)
    {
        return sum;
    }
    int tmp = 0;
    for (int i = 0; i < 3; i++)
    {
        if ((x == N - 1) && (first_index == i))
        {
            continue;
        }
        if (pre_index == i)
        {
            continue;
        }
        choice[x] = i;
        sum += cost[x][i];
        tmp = solve(x + 1, sum);
        min_sum = min(min_sum, tmp);
        sum -= cost[x][i];
    }
    return min_sum;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }

    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        sum = 0;
        choice[0] = j;
        sum += cost[0][j];
        sum = solve(1, sum);

        min_cost = min(min_cost, sum);
    }

    cout << min_cost << "\n";

    return 0;
}