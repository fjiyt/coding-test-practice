#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 25
#define DIR_NUM 4

using namespace std;

int n, m;

int MAP[MAX_N][MAX_N];

vector <pair<int,int>> attack(m);
vector <pair<int,int>> Spiral;

int a_dx[] = {0,1,0,-1};
int a_dy[] = {1,0,-1,0};

int total = 0;

void Print()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void setSpiral()
{
    int dx[] = {0,1,0,-1};
    int dy[] = {-1,0,1,0};

    int x = n/2, y = n/2;
    int idx = 0;
    int num = 1;

    while(x || y)
    {
        for(int i=0; i<num; i++)
        {
            x += dx[idx];
            y += dy[idx];

            Spiral.push_back({x,y});
            if(x==0 && y==0) break;
        }
        
        idx = (idx + 1) % 4;
        if(idx==0 || idx==2) num++;
    }
}
void monster_attack(int d, int p)
{
    int x = n/2;
    int y = n/2;

    for(int i=0; i<p; i++)
    {
        x += a_dx[d];
        y += a_dy[d];

        if(x < 0 || y < 0 || x >= n || y >= n) break;
        total += MAP[x][y];
        MAP[x][y] = 0;
    }

    return;
}
void monster_fill()
{
    int tmp[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[i][j]=0;
        }
    }

    int idx = 0;
    int tmp_idx = 0;
    while(idx < n*n-1)
    {
        int mx = Spiral[idx].first;
        int my = Spiral[idx].second;
        if(MAP[mx][my])
        {
            int x = Spiral[tmp_idx].first;
            int y = Spiral[tmp_idx].second;
            tmp[x][y] = MAP[mx][my];
            tmp_idx++;
        }
        idx++;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            MAP[i][j] = tmp[i][j];
        }
    }
}

int GetNumBySpiralIdx(int idx)
{
    int x, y;
    tie(x,y) = Spiral[idx];

    return MAP[x][y];
}

int GetEndIdxOfSameNum(int idx)
{
    int num = GetNumBySpiralIdx(idx);
    int end_of_array = (int)Spiral.size();
    int end_idx = idx + 1;

    while(end_idx < end_of_array)
    {
        if(GetNumBySpiralIdx(end_idx)==num)
        {
            end_idx++;
        }
        else break;
    }

    return end_idx - 1;
}

void Remove(int start_idx, int end_idx)
{
    for(int i=start_idx; i<=end_idx; i++)
    {
        int x, y;
        tie(x,y) = Spiral[start_idx];
        total += MAP[x][y];
        MAP[x][y] = 0;
    }
}

bool bomb()
{
    bool did_explode = false;
    int cur_idx = 0;
    int end_of_array = (int)Spiral.size();

    while(cur_idx < end_of_array) {
        int end_idx = GetEndIdxOfSameNum(cur_idx);
        int cur_num = GetNumBySpiralIdx(cur_idx);

        if(cur_num==0)
        {
            break;
        }
        if(end_idx - cur_idx + 1 >= 4)
        {
            Remove(cur_idx, end_idx);
            did_explode = true;
        }

        cur_idx = end_idx + 1;
    }

    return did_explode;
}
void organize()
{
    while(1)
    {
        bool keep_going = bomb();

        if(!keep_going) break;

        monster_fill();
    }
}
void make_array()
{
    int temp[n][n];
    // Step 1. temp 배열을 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[i][j] = 0;
    
    // Step2. 보고 말하며 temp에 해당 값을 기록합니다.
    int temp_idx = 0;

    int curr_idx = 0;
    int end_of_array = (int) Spiral.size();
    while(curr_idx < end_of_array) {
        int end_idx = GetEndIdxOfSameNum(curr_idx);

        // 연속하여 나온 숫자의 개수와 숫자 종류 값을 계산합니다.
        int contiguous_cnt = end_idx - curr_idx + 1;
        int curr_num = GetNumBySpiralIdx(curr_idx);

        // 맨 끝에 도달하게 되면, 더이상 진행하지 않습니다.
        if(curr_num == 0)
            break;

        // temp에 (개수, 종류) 순서대로 기록해줍니다.
        // 만약 격자를 벗어나면 종료합니다.
        if(temp_idx >= end_of_array)
            break;
        
        int tx, ty;
        tie(tx, ty) = Spiral[temp_idx];
        temp[tx][ty] = contiguous_cnt;
        temp_idx++;

        if(temp_idx >= end_of_array)
            break;

        tie(tx, ty) = Spiral[temp_idx];
        temp[tx][ty] = curr_num;
        temp_idx++;

        // 그 다음 구간의 시작값으로 변경해줍니다.
        curr_idx = end_idx + 1;
    }

    // Step 3. temp 값을 다시 grid에 옮겨줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            MAP[i][j] = temp[i][j];
}
void solve()
{
    // 나선형 순서 저장
    setSpiral();
    // 1. 몬스터 공격해서 없애기 -> 점수계산
    // 2. 빈공간 채우기
    // 3. 4번 이상 반복하는 몬스터 삭제 -> 안나올때까지 반복 -> 점수계산
    // 4. 몬스터 나열했을때 짝지어서 배열 만들기
    // 5. 다시 미로에 넣기
    for(int i=0; i<m; i++)
    {
        monster_attack(attack[i].first, attack[i].second);
        monster_fill();
        
        organize();
        make_array();
    }

    cout << total << "\n";
}
int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for(int i=0; i<m; i++)
    {
        int d, p;
        cin >> d >> p;
        attack.push_back({d,p});
    }

    solve();
    return 0;
}