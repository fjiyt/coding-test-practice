#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
vector <int> bottom;
vector <int> top;

int min_catch=1e9;
int min_cnt=0;

void solve()
{
    for(int i=1; i<=H; i++)
    {
        int idx1 = lower_bound(bottom.begin(), bottom.end(), i)-bottom.begin();
        int idx2 = upper_bound(top.begin(), top.end(), H-i)-top.begin();
        
        int cnt = bottom.size()-idx1 + top.size() - idx2;
        if(min_catch > cnt)
        {
            min_catch = cnt;
            min_cnt=1;
        }
        else if(min_catch==cnt)
        {
            min_cnt++;
        }
    }
    
    cout << min_catch << " " << min_cnt << "\n";
}
int main()
{
    cin >> N >> H;
    for(int i=0; i<N/2; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        bottom.push_back(num1);
        top.push_back(num2);
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());
    
    solve();
}