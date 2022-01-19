//전형적인 투포인터
#include <iostream>
#include <algorithm>

using namespace std;
int N;
int ans = 0;
int arr[2001];

void two_pointer(int goal)
{
    int left = 0, right = N - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum < arr[goal])
        {
            left++;
        }
        else if (sum > arr[goal])
        {
            right--;
        }
        else
        {
            if (left == goal)
                left++;
            else if (right == goal)
                right--;
            else
            {
                ans++;
                break;
            }
        }
    }

    return;
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

    if (N < 3)
    {
        cout << "0\n";
        return 0;
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        two_pointer(i);
    }

    cout << ans << "\n";
}