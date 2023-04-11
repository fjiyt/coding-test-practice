#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int d = 1;
    int cnt = 0;
    while(N>0)
    {
        N-=d;
        cnt++;
        d=6*cnt;
    }

    cout << cnt << "\n";
}