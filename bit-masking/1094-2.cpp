#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int ans = 0;
    int cnt = 0;
    while(N > 0)
    {
        if(N%2==1)
        {
            cnt++;
        }
        N/=2;
    }

    cout << cnt << "\n";
}