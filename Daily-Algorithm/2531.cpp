//BOJ 15961번: 회전 초밥
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 3000000
using namespace std;

int arr[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    vector<int> v;
    int n, d, k, c, num = -1;
    int start = 0, end, total;
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < k; i++)
        v.push_back(arr[i]);

    end = k - 1;
    total = k;

    while (start < n)
    {
        if (total == k)
        {
            if (end == n)
            {
                end = 0;
            }

            if (s.size() == k)
            {
                s.insert(c);
                num = max(num, (int)s.size());
                if (num == k + 1)
                    break;
            }

            v.erase(v.begin(), v.begin() + 1);
            v.push_back(arr[++end]);
            start++;
            s.clear();
        }
    }

    cout << num;

    return 0;
}