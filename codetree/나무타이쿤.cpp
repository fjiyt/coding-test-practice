#include <iostream>
#include <vector>

using namespace std;

int n, m;
int d, p;
int MAP[16][16];

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

vector <pair<int,int>> nutrients;

void move()
{
    for(int i=0; i<nutrients.size(); i++)
    {
        int x = nutrients[i].first + dx[d] * p;
        int y = nutrients[i].second + dy[d] * p;

        x = (x+n) % n;
        y = (y+n) % n;

        nutrients[i].first = x;
        nutrients[i].second = y;
    }
}
void grow()
{
    for(int i=0; i<nutrients.size(); i++)
    {
        int x = nutrients[i].first;
        int y = nutrients[i].second;
        MAP[x][y]++;
    }
    for(int i=0; i<nutrients.size(); i++)
    {
        int x = nutrients[i].first;
        int y = nutrients[i].second;
        //대각선 탐색
        for(int j=1; j<8; j++)
        {
            if(j%2==0) continue;
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx < 0 || ny < 0 || nx >= n || ny >=n ) continue;
            if(MAP[nx][ny]>=1) { MAP[x][y]++;}
        }
    }
}
bool isNutrients(int x,int y)
{
    for(int i=0; i<nutrients.size(); i++)
    {
        if(nutrients[i].first == x && nutrients[i].second == y) return true;
    }

    return false;
}
void cut()
{
    vector <pair<int,int>> tmp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(isNutrients(i,j)) continue;
            if(MAP[i][j] >= 2){MAP[i][j] -= 2; tmp.push_back({i,j});} 
        }
    }

    nutrients.clear();
    for(int i=0; i<tmp.size(); i++)
    {
        nutrients.push_back({tmp[i].first, tmp[i].second});
    }
}
void solve()
{
    // 1. 영양제 이동
    move();
    // 2. 리브로스 성장
    grow();
    // 3. 영양제 투입한 곳 제외하고 2이상인 곳 자르기 -> 영양제 두기
    cut();
}
void calculate()
{
    int total = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            total += MAP[i][j];
        }
    }

    cout << total << "\n";
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    nutrients.push_back({n-2,0});
    nutrients.push_back({n-2,1});
    nutrients.push_back({n-1,0});
    nutrients.push_back({n-1,1});

    while(m--)
    {
        cin >> d >> p;
        d--;
        solve();
    }

    // 리브로수 총 합
    calculate();

}