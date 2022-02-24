#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int N;
int min_diff = 1010;
int people[12];
bool isVisited[12];
bool map[12][12];
queue <int> section;
queue <int> que;

void BFS(int start)
{
    que.push(start);
    isVisited[start] = true;

    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        section.push(now);

        while(!map[now].empty())
        {
            int next = map[now].front();
            map[now].pop();

            if(!isVisited[next])
            {
                que.push(next);
                isVisited[next] = true;
            }
        }
    }
}
void Solve()
{
    DFS(1,0); //조합 구하기
}
int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> people[i];
    }
    for(int i=1; i<=N; i++)
    {
        int j;
        cin >> j;
        while(j--)
        {
            int num;
            cin >> num;
            map[i][num] = true;
        }
    }
    Solve();

    cout << min_diff << "\n";
}