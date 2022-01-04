#include <iostream>
#include <vector>

using namespace std;
int N, Q;
vector<int> arr;
vector<int> cnt;

int Solve(int start, int end)
{
    int tmp = cnt[end - 1];
    if (start > 1)
    {
        tmp -= cnt[start - 2];
    }
    if (end < N && arr[end - 1] > arr[end])
    {
        tmp--;
    }

    return tmp;
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
        arr.push_back(num);
    }
    int tmp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        tmp = 0;
        if (i > 0)
            tmp = cnt[i - 1];
        if (arr[i] > arr[i + 1])
        {
            tmp++;
            cnt.push_back(tmp);
        }
        else
        {
            cnt.push_back(tmp);
        }
    }

    cnt.push_back(tmp);
    cin >> Q;
    while (Q > 0)
    {
        int start, end;
        cin >> start >> end;
        int ret = Solve(start, end);
        cout << ret << " ";
        Q--;
    }
    cout << "\n";
}