#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001] = {
    0,
};
int best_min = 0; //최소거리 중 최댓값
int N, C;

int main()
{
    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + N);
    int left = 1;
    int right = arr[N - 1];

    int mid = 0;
    while (left <= right)
    {
        int cnt = 1; // 공유기 개수
        int cur_index = 0;
        mid = (left + right) / 2;

        for (int i = 1; i < N; i++)
        {
            if (arr[i] - arr[cur_index] >= mid)
            {
                cnt++;
                cur_index = i;
            }
        }

        if (cnt >= C)
        {
            left = mid + 1;
            best_min = max(best_min, mid);
        }
        else if (cnt < C)
        {
            right = mid - 1;
        }
    }

    cout << best_min << "\n";

    return 0;
}