#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> bottom;
vector <int> top;
int N, H;
int cnt = 0;
int minimum = 200001;

void solve()
{
    for(int i=1; i<=H; i++)
    {
        int idx1 = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
        int idx2 = upper_bound(top.begin(), top.end(), H-i) - top.begin();
        int tmp = N - idx1 - idx2;

        if(minimum == tmp){
            cnt++;
        }
        else if(minimum > tmp) {
            minimum = tmp;
            cnt = 1;
        }
    }
}
int main()
{
    cin >> N >> H;
    for(int i=0; i<N/2; i++)
    {
        int a,b;
        cin >> a >> b;
        bottom.push_back(a);
        top.push_back(b);
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());
    solve();
    cout << minimum << " " << cnt << "\n";
}