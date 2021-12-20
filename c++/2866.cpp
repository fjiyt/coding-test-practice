#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;
int cnt = 0;
char arr[1001][1001];
int row, column;

bool check(int start, int end)
{
    set<string> s;

    for (int i = 0; i < column; i++)
    {
        string tmp;
        for (int j = start; j <= end; j++)
        {
            tmp.push_back(arr[j][i]);
        }

        if (s.find(tmp) == s.end())
        {
            s.insert(tmp);
        }
        else
            return false;
    }

    return true;
}
void binarySearch(int left, int right, int end)
{
    if (left > right)
        return;
    int mid = (left + right) / 2;
    bool flag = check(mid, end);
    if (!flag) //동일한 문자열 발견
    {
        binarySearch(left, mid - 1, end);
    }
    else
    { //동일한 문자열이 없을 경우
        if (cnt < mid)
            cnt = mid;

        binarySearch(mid + 1, right, end);
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> row >> column;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }

    //같은 문자열 확인
    binarySearch(1, row - 1, row - 1);

    cout << cnt << "\n";
    return 0;
}