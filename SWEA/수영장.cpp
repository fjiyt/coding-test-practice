#include <iostream>
#include <algorithm>

using namespace std;

int arr[13];
int dp[13];
int day, month, months, year;
void solve()
{
    dp[1] = min({arr[1] * day, month, year});
    dp[2] = min({dp[1]+arr[2]*day, dp[1]+month, year});

    for(int i=3; i<=12; i++)
    {
        dp[i] = min({dp[i-1]+arr[i]*day, dp[i-1]+month, dp[i-3]+months, year});
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> day >> month >> months >> year;
        for(int i=1; i<=12; i++)
        {
            cin >> arr[i];
        }
        solve();
        cout << "#" << test_case << " " << dp[12] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}