// 지나온 경로 중 최소값
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<pair<int, int> > a[100001];
bool isVisited[100001] = {
    false,
};

int max_weight = 0;
//두 공장
int to, from;
// 결국 경로상 가장 작은 무게 -> 두 공장을 이동하는데에 필요한 무게
bool bfs(int goal_weight)
{
    memset(isVisited, false, sizeof(isVisited));
    queue<int> que;
    que.push(to);
    isVisited[to] = true;
    while (!que.empty())
    {
        int cur_num = que.front();
        que.pop();

        if (cur_num == from)
        {
            return true;
        }
        for (int i = 0; i < a[cur_num].size(); i++)
        {
            int next_num = a[cur_num][i].first;
            int next_weight = a[cur_num][i].second;

            if (!isVisited[next_num] && goal_weight <= next_weight)
            {
                isVisited[next_num] = true;
                que.push(next_num);
            }
        }
    }

    return false;
}
int solve()
{
    //이진탐색
    int left = 0;
    int right = max_weight;
    int mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (bfs(mid))
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return right;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int num1, num2, weight;
        cin >> num1 >> num2 >> weight;

        a[num1].push_back(make_pair(num2, weight));
        a[num2].push_back(make_pair(num1, weight));
        if (weight > max_weight)
            max_weight = weight;
    }
    cin >> to >> from;
    int ret;
    ret = solve();
    cout << ret << "\n";

    return 0;
}