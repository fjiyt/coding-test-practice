#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstdlib>

using namespace std;

int n,k;
int arr[101];
int total_cnt = 0;

void add_flour()
{
    int min_value = 3001;
    for(int i=0; i<n; i++)
    {
        min_value = min(min_value, arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        if(min_value == arr[i]) arr[i]++;
    }
}

void Move(vector<pair<int,int>> &dough, int row)
{
    for(int i=0; i< dough.size(); i++)
    {
        int x = dough[i].first;
        int y = dough[i].second;
        dough[i].first = y;
        dough[i].second = row - x + 1;   
    }
}

vector <pair<int,int>> roll()
{
    vector <pair<int,int>> dough(n);

    dough[0] = {1,1};
    dough[1] = {2,1};
    int dough_row = 2;
    int dough_column = 1;
    int idx = 2;

    // 새로 만 도우 row < 바닥에 있는 밀가루
    while(dough_row <= n-idx)
    {
        Move(dough, dough_row);
        
        //새로운 밀가루 추가
        for(int i=1; i<=dough_row; i++)
        {
            dough[idx++] = {dough_column+1,i};
        }

        if(dough_row == dough_column+1)
        {
            dough_column++;
        }
        else{
            dough_row++;
        }
    }

    // 남은 밀가루 -> n-idx
    int cnt = 1;
    while(idx < n) {
        dough[idx++] = {dough_row, dough_column+cnt};
        cnt++;
    }

    return dough;
}

void press(vector <pair<int,int>> dough)
{
    int temp[101];
    for(int i=0; i<n; i++)
    {
        int x = dough[i].first;
        int y = dough[i].second;
        for(int j=i+1; j<n; j++)
        {
            int nx = dough[j].first;
            int ny = dough[j].second;

            //인접한지 확인
            if(abs(nx-x) + abs(ny-y) == 1)
            {
                int d = abs(arr[i]-arr[j]) / 5;
                if(arr[i] < arr[j])
                {
                    temp[i] = arr[i]+d;
                    temp[j] = arr[j]-d;
                }
                else{
                    temp[i] = arr[i]-d;
                    temp[j] = arr[j]+d;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = temp[i];
    }

    //나열 -> 열 오름차순, 행 내림차순
    for(int i=0; i<n; i++)
    {
        temp[i]=0;
    }
    vector <tuple<int,int,int>> sort_dough;
    for(int i=0; i<n; i++)
    {
        int x = dough[i].first;
        int y = dough[i].second; 
        sort_dough.push_back({y, -x, arr[i]});
    }
    sort(sort_dough.begin(), sort_dough.end());

    for(int i=0; i<n; i++)
    {
        int x, y;
        tie(x,y,temp[i])=sort_dough[i];
    }

    for(int i=0; i<n; i++)
    {
        arr[i] = temp[i];
    }
}

vector <pair<int,int>> fold()
{
    vector <pair<int,int>> dough(n);
    //첫번째 접기
    for(int i=0; i<n/2; i++)
    {
        dough[i] = {1, n/2-i};
    }
    for(int i=n/2; i<n; i++)
    {
        dough[i] = {2, i-(n/2)+1};
    }
    
    //두번째 접기
    for(int i=0; i<n; i++)
    {
        int x = dough[i].first;
        int y = dough[i].second;

        if(y <= n/4)
        {
            dough[i] = {3-x, n/4 - y +1};
        }
        else{
            dough[i] = {x+2, y-n/4};
        }
    }

    return dough;
}

int test()
{
    int min_value = 3000;
    int max_value = 0;
    int diff = 3000;

    for(int i=0; i<n; i++)
    {
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
        diff = max_value - min_value;
    }

    return diff;
}
void solve()
{

    bool isEnd = false;

    while(!isEnd)
    {
        // 1번) 밀가루 가장 작은 위치에 밀가루 1 추가
        add_flour();
        // 2번) 도우를 말아준다
        vector <pair<int,int>> dough = roll();
        // 3번) 도우를 꾹 눌러준다
        press(dough);
        // 4번) 도우를 두번반 접는다
        dough = fold();
        // 5번) 3의 과정 반복
        press(dough);

        total_cnt++;

        if(test()<=k){
            isEnd = true;
            return;
        }
        
    }
    
}
int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    solve();

    cout << total_cnt << "\n";
}