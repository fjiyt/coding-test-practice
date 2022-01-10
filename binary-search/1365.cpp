/*
@author jy111099
@date 2021-01-10
@question BOJ-1365 [꼬인 전깃줄]
@solution binary-search / LIS
*/
#include <iostream>
#include <vector>

using namespace std;

int N;
int wire[100001];
vector<int> lis;

void solve()
{
    lis.push_back(wire[0]);
    for (int i = 1; i < N; i++)
    {
        if (lis.back() < wire[i])
        {
            lis.push_back(wire[i]);
        }
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), wire[i]) - lis.begin();
            lis[idx] = wire[i];
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> wire[i];
    }

    solve();
    int length = N - lis.size();
    cout << length << "\n";
}