#include <iostream>

using namespace std;

int H, W, N, M;
int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W >> N >> M;

    int r_cnt = H/(N+1);
    if(H%(N+1)>0) r_cnt++;

    int c_cnt = W/(M+1);
    if(W%(M+1) >0) c_cnt++;
    
    cout << r_cnt*c_cnt << "\n";
}