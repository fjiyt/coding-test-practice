#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

vector <int> v[MAX];
queue <int> q;
int d[MAX]={0,};
int N, M;

void topologySort()
{
    int result[MAX];

    for(int i=1; i<=N; i++)
    {
        if(d[i]==0)
        {
            q.push(i);
        }
    }

    for(int i=1; i<=N; i++)
    {
        if(q.empty())
        {
            cout << "0\n";
            return;
        }

        int num = q.front();
        q.pop();
        result[i] = num;
        for(int j=0; j<v[num].size(); j++)
        {
            int num2 = v[num][j];
            d[num2]--;

            if(d[num2]==0)
            {
                q.push(num2);
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
        cout << result[i] << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<M; i++)
    {
        int T;
        cin >> T;

        int  now = 0, past = 0;
        for(int j=0; j<T; j++)
        {
            cin >> now;
            if(past == 0) {
                past = now;
                continue;
            }
            v[past].push_back(now);
            d[now]++;
            past = now;
        }
    }

    topologySort();

    return 0;
}