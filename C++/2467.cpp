#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int N;
vector<int> v;
int num1, num2;

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
    //둘다 알카리성 (-)
    if (v[N - 1] < 0)
    {
        cout << v[N - 2] << " " << v[N - 1] << "\n";
        return 0;
    }
    //둘다 산성 (+)
    else if (v[0] > 0)
    {
        cout << v[0] << " " << v[1] << "\n";
        return 0;
    }
    //섞여있을 때
    else
    {
        int left = 0, right = N - 1;
        int min_value = abs(v[left] + v[right]);
        num1 = v[left];
        num2 = v[right];
        while (left < right)
        {
            int tmp = v[left] + v[right];
            if (abs(tmp) < min_value)
            {
                min_value = abs(tmp);
                num1 = v[left];
                num2 = v[right];
            }
            if (tmp < 0)
            {
                left++;
            }
            else if (tmp > 0)
            {
                right--;
            }
            else
                break;
        }

        cout << num1 << " " << num2 << "\n";
        return 0;
    }
}