#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> v;
bool used[21] = {
    false,
};

void solve1(int order)
{
    long long factorial = 1;
    int i = N - 1;
    while (i > 0)
    {
        factorial *= i;
        i--;
    }

    int tmp = order;
    for (i = 0; i < N; i++)
    {
        int num = 0;
        while (tmp >= 0)
        {
            tmp -= factorial;
            num++;
        }

        tmp += factorial;
        num--;

        int start = 1;
        while (num > 0)
        {

            num--;
        }

        factorial = factorial / (N - (i + 1));
    }

    return;
}
void solve2()
{
    vector<int> input;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        int used_cnt = 0;
        int in = input[i] - 1;
        for (int j = 0; j < in; j++)
        {
            if (!used[j])
            {
                used_cnt++;
            }
        }
        used[in] = true;
        total += used_cnt;
        if (i != N - 1)
            total *= N - (i + 1);
    }
    total++;

    cout << total << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        v.push_back(i + 1);
    }

    int num;
    cin >> num;

    switch (num)
    {
    case 1:
        int order;
        cin >> order;
        solve1(order);
        break;
    case 2:
        solve2();
        break;
    }

    return 0;
}