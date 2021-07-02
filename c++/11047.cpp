#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,K;
    cin >> N >> K;

    int order[N];
    int cnt=0; //사용한 동전 개수

    for(int i=0; i<N; i++)
    {
        cin >> order[i];
    }

    for(int i=N-1; i>=0; i--)
    {
        if(K == 0) break;
        if(order[i] <= K){ 
            cnt += K / order[i];
            K %= order[i];
        }
    }

    cout << cnt <<"\n";
    return 0;
}