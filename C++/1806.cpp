/* 
    투포인터인지 확인하는 방법 
    - 수열에서 연속된 수의 합을 구한다. 즉 구간합을 구한다. 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, S;

void solve()
{
    int start = 0, end = 0;
    int summary = 0;
    int min_length = N + 1;

    for (start = 0; start < N; start++)
    {
        while ((summary < S) && (end < N))
        {
            summary += v[end];
            end++;
        }
        if (summary >= S)
        {
            int length = end - start;
            min_length = min(min_length, length);
        }
        summary -= v[start];
    }
    if (min_length == N + 1)
    {
        min_length = 0;
    }

    cout << min_length << "\n";
}
int main()
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        v.push_back(num);
    }

    solve();

    return 0;
}