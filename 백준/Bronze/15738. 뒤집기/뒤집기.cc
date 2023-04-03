#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector <int> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> M;
    for(int i=1; i<=N; i++)
    {
        int num;
        cin >> num;
        v.push_back(i);
    }

    while(M--)
    {
        int num;
        cin >> num;

        if(num > 0)
        {
            reverse(v.begin(), v.begin()+num);
        }
        else
            reverse(v.end()+num, v.end());
    }

    for(int i=0; i<N; i++)
    {
        if(v[i]==K) {
            cout << i+1 << "\n";
            break;
        }
    }
}