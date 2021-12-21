#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdbool.h>

using namespace std;
int N, M, L;
vector<int> v; //위치 저장

bool solve(int interval)
{
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        int distance = v[i + 1] - v[i];
        int tmp = distance / interval;
        if (tmp > 0)
        {
            if (distance % interval == 0)
            {
                cnt += (tmp - 1);
            }
            else
            {
                cnt += tmp;
            }
        }
    }
    if (cnt <= M)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> L;
    v.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(L);
    sort(v.begin(), v.end());

    int left, right, mid, answer;
    left = 1;
    right = L;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (solve(mid))
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}