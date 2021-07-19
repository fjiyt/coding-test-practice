#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int alphabet[26] = {
    0,
};
int total = 0;

bool desc(int a, int b)
{
    return a > b;
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            int ascii = str[j] - 65;
            int location = str.length() - j;
            alphabet[ascii] += pow(10, location - 1);
        }
    }

    sort(alphabet, alphabet + 26, desc);

    int temp = 9;

    for (int i = 0; i < 10; i++)
    {
        total += alphabet[i] * temp;
        temp--;
    }

    cout << total << "\n";

    return 0;
}