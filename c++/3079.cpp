#include <iostream>
#include <algorithm>

using namespace std;

long long T[100002] = {0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        cin >> T[i];
    }

    sort(T, T+N);

    long long left=0, right=T[N-1]*M, result = right;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long num = 0;
        for(int i=0; i<N; i++)
        {
            num += mid / T[i];
        }
        if(num < M)
        {
            left = mid + 1;
        }

        else{
            if(result > mid) result = mid;
            right = mid - 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}