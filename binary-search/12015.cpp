/*
@author jy111099
@date 2021-01-10
@question BOJ-12015 [가장 긴 증가하는 부분 수열2]
@solution binary-search / LIS
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000001];
vector<int> v;

int LIS()
{
    v.push_back(arr[0]);
    for (int i = 0; i < N; i++)
    {
        if (v.back() < arr[i])
            v.push_back(arr[i]);
        else
        {
            *(lower_bound(v.begin(), v.end(), arr[i])) = arr[i];
        }
    }

    return v.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int ret = LIS();
    cout << ret << "\n";
}