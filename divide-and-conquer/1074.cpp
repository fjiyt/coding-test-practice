#include <iostream>
#include <cmath>

using namespace std;
long long cnt;
int N, r, c;

void solve(int size, int x, int y)
{
    if(x==r && y==c) {
        cout << cnt << "\n";
        return;
    }
    if(r < x+size && r >=x && c < y+size && c >=y && size > 0)
    {
        solve(size/2, x, y);
        solve(size/2, x, y+size/2);
        solve(size/2, x+size/2, y);
        solve(size/2, x+size/2, y+size/2);
    }
    else{
        cnt += size * size;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> r >> c;
    solve(pow(2,N),0,0);
}