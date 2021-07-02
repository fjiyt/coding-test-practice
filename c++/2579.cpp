#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int stair[302] = {0,};
int DP[302] = {0,};

void solution(int n)
{
    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];
    DP[3] = max(DP[1]+stair[3], stair[2]+stair[3]);
    if(n<=3) return;
    for(int i=4; i<=n; i++)
    {
        DP[i] = max(DP[i-3]+stair[i-1]+stair[i], DP[i-2]+stair[i]);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
    {
        cin >> stair[i];
    }

    solution(N);
    cout << DP[N] << "\n";

    return 0;
}