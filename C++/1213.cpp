#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string str;
string new_str;
char mid;
int arr[26] = {
    0,
};

bool isEven()
{
    int num = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 == 1)
        {
            num++;
            if (num >= 2)
                return false;
            if (num == 1)
                mid = i + 65;
        }
    }
    return true;
}
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        arr[(int)str[i] - 65]++;
    }

    if (!isEven())
    {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < arr[i] / 2; j++)
        {
            char c = i + 65;
            new_str.push_back(c);
        }
    }
    string tmp_str = new_str;
    reverse(tmp_str.begin(), tmp_str.end());
    if (mid)
    {
        new_str.push_back(mid);
    }

    new_str.append(tmp_str);

    cout << new_str << "\n";
    return 0;
}