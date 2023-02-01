#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long ans=0;
    for(int i=1; i<=N; i*=10)
    {
        ans += N - i + 1;
    }

    cout << ans << "\n";
}