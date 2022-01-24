/*
@author jy111099
@date 2021-01-24
@question BOJ-10800 [컬러볼]
@solution prefix_sum
*/
#include <iostream>

using namespace std;

int N;
int arr[1000002];
int lgcd[1000002], rgcd[1000002];
int num, max_gcd = -1, cnt;

int gcd(int a,int b)
{
    if(b==0) return a;
    int mod = a%b;

    while(mod > 0)
    {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> arr[i];
    }
    for(int i=1; i<=N; i++) lgcd[i] = gcd(arr[i], lgcd[i-1]);
    for(int i=N; i>0; i--) rgcd[i] = gcd(arr[i], rgcd[i+1]);

    for(int i=1; i<=N; i++)
    {
        int tmp = gcd(lgcd[i-1], rgcd[i+1]);
        if(max_gcd <= tmp)
        {
            max_gcd = tmp;
            num = arr[i];
            cnt++;
        }
    }

    if(cnt < N)
    {
        cout << max_gcd << " " << num << "\n";
    }
    else cout << -1 << "\n";
}