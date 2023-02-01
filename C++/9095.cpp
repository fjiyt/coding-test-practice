#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int DP[11] = {0,};

void makeNum(int N)
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    if(N <= 3) return;

    for(int i=4; i<=N; i++)
    {
        if(DP[i] > 0) continue;
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    for(int i=0; i<T; i++)
    {
        int num;
        cin >> num;

        makeNum(num);
        cout << DP[num] << "\n";
    }

    return 0;
}