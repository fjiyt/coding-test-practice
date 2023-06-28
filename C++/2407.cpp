#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    unsigned long long num = 1;
    for(int i=n; i>n-m; i--)
    {
        num = num * i;
    }
    unsigned long long sub = 1;
    for(int i=m; i>0; i--)
    {
        sub = sub * i;
    }
    num /= sub;

    cout << num << "\n";
}