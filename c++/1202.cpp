#include <iostream>
#include <queue>
#include <set>

using namespace std;

multiset<int> ms;
long long total = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;

    cin >> N >> K;

    priority_queue<pair<int, int> > pq;

    for (int i = 0; i < N; i++)
    {
        int weight, value;

        cin >> weight >> value;

        pq.push(make_pair(value, weight));
    }

    for (int i = 0; i < K; i++)
    {
        int weight;
        cin >> weight;
        ms.insert(weight);
    }

    //돌면서 최적의 범위를 찾는다.
    int cnt = 0;
    multiset<int>::iterator it;
    while (!pq.empty())
    {
        if (cnt > K) //가방을 다 쓴 경우
        {
            break;
        }
        int weight = pq.top().second;
        int value = pq.top().first;
        pq.pop();

        multiset<int>::iterator final;
        final = ms.lower_bound(weight);

        if (final != ms.end())
        {
            ms.erase(final);
            total += value;
            cnt++;
        }
    }

    cout << total << "\n";

    return 0;
}