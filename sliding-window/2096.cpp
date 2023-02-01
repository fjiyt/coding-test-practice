/*
@author jy111099
@date 2021-01-19
@question BOJ-2096 [내려가기]
@solution dynamic programing
@caution 메모리초과 주의
*/
#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[3];
int max_dp[2][3];
int min_dp[2][3];
int max_ret = 0;
int min_ret = 1000000;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int j = 0; j < 3; j++)
    {
        cin >> arr[j];
        max_dp[0][j] = arr[j];
        min_dp[0][j] = arr[j];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j];
        }
        max_dp[1][0] = max(max_dp[0][0] + arr[0], max_dp[0][1] + arr[0]);
        max_dp[1][1] = max(max(max_dp[0][0] + arr[1], max_dp[0][1] + arr[1]), max_dp[0][2] + arr[1]);
        max_dp[1][2] = max(max_dp[0][1] + arr[2], max_dp[0][2] + arr[2]);

        min_dp[1][0] = min(min_dp[0][0] + arr[0], min_dp[0][1] + arr[0]);
        min_dp[1][1] = min(min(min_dp[0][0] + arr[1], min_dp[0][1] + arr[1]), min_dp[0][2] + arr[1]);
        min_dp[1][2] = min(min_dp[0][1] + arr[2], min_dp[0][2] + arr[2]);

        for (int j = 0; j < 3; j++)
        {
            max_dp[0][j] = max_dp[1][j];
            min_dp[0][j] = min_dp[1][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        max_ret = max(max_ret, max_dp[0][i]);
        min_ret = min(min_ret, min_dp[0][i]);
    }

    cout << max_ret << " " << min_ret << "\n";
}