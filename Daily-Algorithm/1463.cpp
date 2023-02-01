#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int DP[1000001]={0,};

int main()
{
    int N;
    cin >> N;

    DP[1] = 0;
    for(int i=2; i<=N; i++)
    {
        DP[i] = DP[i-1] + 1;
        if(i%3==0) DP[i] = min(DP[i], DP[i/3]+1);
        if(i%2==0) DP[i] = min(DP[i], DP[i/2]+1);
    }

    cout << DP[N] << "\n";
    return 0;
}