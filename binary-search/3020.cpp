/*
@author jy111099
@date 2021-01-03
@question BOJ-3020 [개똥벌레]
@solution binary-search
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
vector<int> top;
vector<int> bottom;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> H;
    for (int i = 0; i < N / 2; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        bottom.push_back(num1);
        top.push_back(num2);
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int ans = 200001;
    int cnt = 0;
    for (int i = 1; i <= H; i++)
    {
        int num = 0;
        int idx = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
        num += N / 2 - idx;

        idx = upper_bound(top.begin(), top.end(), H - i) - top.begin();
        num += N / 2 - idx;
        if (ans == num)
            cnt++;
        else if (num < ans)
        {
            ans = num;
            cnt = 1;
        }
    }

    cout << ans << " " << cnt << "\n";
}