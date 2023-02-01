#include <iostream>

using namespace std;
struct calendar
{
    int day;
    int pay;
};

int dp[16] = {
    0,
};
int main()
{
    int N;
    cin >> N;

    calendar c[N + 1];

    for (int i = 1; i <= N; i++)
    {
        cin >> c[i].day >> c[i].pay;
    }

    int max_pay = 0;
    for (int i = 1; i <= N; i++)
    {
        int next = i + c[i].day;

        //해당일에 일을 할 수 있는 경우
        if (next - 1 <= N)
        {
            dp[i] += c[i].pay;
            if (dp[i] > max_pay)
            {
                max_pay = dp[i];
                for (int j = next; j <= N; j++)
                {
                    dp[j] = max_pay;
                }
            }

            else if (next - 1 < N)
            {
                dp[next] = max(dp[next], dp[i]);
            }
        }
        else
        {
            dp[i] = max_pay;
        }
    }

    max_pay = max(max_pay, dp[N]);
    cout << max_pay << "\n";

    return 0;
}