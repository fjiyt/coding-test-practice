#include <iostream>
#include <algorithm>

using namespace std;

long long LAN[10002] = {0,}; //이미 있는 랜선

int main()
{
    int K, N;
    cin >> K >> N;

    for(int i=0; i<K; i++)
    {
        cin >> LAN[i];
    }
    sort(LAN, LAN+K); //랜선 정렬
    long long left = 1, right = LAN[K-1], goal = 1; // 1부터 가장 긴 랜선까지 이진탐색
    // 랜선의 길이제한 : int 경계에 있어서 long long

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long total = 0;

        for(int i=0; i<K; i++)
        {
            total += LAN[i]/mid; // 자른 랜선 개수
        }

        if(total < N) 
        {
            right = mid-1;
        }
        else 
        {
            goal = mid; // N보다 크거나 같게 나누는 길이의 최대값. 반복하면서 최대값 갱신
            left = mid+1;
        }
    }

    cout << goal << "\n";
    
    return 0;
}