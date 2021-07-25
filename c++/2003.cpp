#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int N, M;
int cnt = 0;

void two_pointer()
{
    int start = 0, end = 0;
    int summary = 0;
    while (start < N)
    {
        while ((summary < M) && (end < N))
        {
            summary += v[end];
            end++;
        }
        if (summary == M)
        {
            cnt++;
        }
        //start 한칸 이동 -> 현재 start 값을 빼줘야함
        summary -= v[start];
        start++;
    }

    cout << cnt << "\n";
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    two_pointer();

    return 0;
}