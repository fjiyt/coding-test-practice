#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int solve()
{
    int left = 0;
    int right = N - 1;
    int min_value = v[left] + v[right];

    while (left < right)
    {
        int tmp = v[left] + v[right];
        if (abs(tmp) < abs(min_value))
        {
            min_value = tmp;
        }
        if (tmp > 0)
        {
            right--;
        }
        else if (tmp < 0)
        {
            left++;
        }
        else
        {
            return 0;
        }
    }

    return min_value;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int ret = 0;
    //모두 음수인 경우
    if (v[N - 1] < 0)
    {
        ret = v[N - 1] + v[N - 2];
    }
    else if (v[0] > 0)
    {
        //모두 양수인 경우
        ret = v[0] + v[1];
    }
    else
    {
        ret = solve();
    }
    cout << ret << "\n";
}