/*
@author jy111099
@date 2021-01-12
@question BOJ-13549 [숨바꼭질3]
@solution Dijkstra / BFS
*/
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dx[] = {-1, 1};
int dp[100001] = {
    0,
};

queue<int> que;

int BFS()
{
    while (!que.empty())
    {
        int current = que.front();
        que.pop();

        if (current == K)
            return dp[current];

        int next = 0;
        for (int i = 0; i < 2; i++)
        {
            next = current + dx[i];
            for (int j = next; j <= 100000; j *= 2)
            {
                if (j < 0 || j > 100000)
                {
                    break;
                }
                if (dp[j] == -1)
                {
                    dp[j] = dp[current] + 1;
                    que.push(j);
                }
                if (j == 0)
                    break;
            }
        }
    }

    return -1;
}
int main()
{
    cin >> N >> K;
    fill_n(dp, 100001, -1);

    for (int i = N; i <= 100000; i *= 2)
    {
        if (i < 0 || i > 100000)
        {
            break;
        }
        if (dp[i] == -1)
        {
            dp[i] = 0;
            que.push(i);
        }
        if (i == 0)
            break;
    }
    int ret = BFS();
    if (ret > -1)
        cout << ret << "\n";
}