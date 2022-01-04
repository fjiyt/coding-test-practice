#include <iostream>

using namespace std;
string str;

int findMax()
{
    int start = 0;
    int end = str.length() - 1;
    int cnt = -1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            cnt = str.length();
            return cnt;
        }
        start++;
        end--;
    }
    start = 0;
    end = str.length() - 2;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            cnt = str.length() - 1;
            return cnt;
        }
        start++;
        end--;
    }

    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;

    cout << findMax() << "\n";

    return 0;
}