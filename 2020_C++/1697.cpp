#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool isVisited[100001] = {
    false,
};
int cal[3] = {-1, 1, 2};

int main(void)
{
    queue<int> que;
    queue<int> cost;

    int N, K;
    cin >> N >> K;

    que.push(N);
    cost.push(0);

    while (!que.empty() && !cost.empty())
    {
        int now = que.front();
        que.pop();

        int time = cost.front();
        cost.pop();

        if (isVisited[now])
            continue;
        isVisited[now] = true;

        if (now == K)
        {
            cout << time << "\n";
            break;
        }

        int next = 0;
        for (int i = 0; i < 3; i++)
        {
            if (cal[i] == 2)
            {
                next = now * cal[i];
            }
            else
            {
                next = now + cal[i];
            }
            if (next >= 0 && next <= 100000)
            {
                que.push(next);
                cost.push(time + 1);
            }
        }
    }

    return 0;
}