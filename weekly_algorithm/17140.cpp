#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int r,c,k;
int arr[102][102];
int cnt[101];
 
int r_operation(int R, int C)
{
    vector <int> size;
    for(int i=1; i<=R; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        priority_queue <pair <int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        int j = 1;
        for(int j=1; j<=C; j++) cnt[arr[i][j]]++;
        for(int j=1; j<=100; j++)
        {
            if(cnt[j] > 0)
            {
                pq.push({cnt[j], j});
            }
        }
        for(int j=1; j<=C; j++) arr[i][j] = 0;
        int idx = 1;
        while(!pq.empty())
        {
            int num1 = pq.top().first;
            int num2 = pq.top().second;
            arr[i][idx++] = num2;
            arr[i][idx++] = num1;
                
            pq.pop();
        }
        idx--;
        size.push_back(idx);
    }
    sort(size.begin(), size.end());
    return size.back();
}
int c_operation(int R, int C)
{
    vector <int> size;
    for(int j=1; j<=C; j++)
    {
        memset(cnt, 0, sizeof(cnt));
        priority_queue <pair <int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(int i=1; i<=R; i++)
        {
            cnt[arr[i][j]]++;
        }
        
        for(int i=1; i<=100; i++)
        {
            if(cnt[i] > 0)
            {
                pq.push({cnt[i], i});
            }
        }
        for(int i=1; i<=R; i++) arr[i][j] = 0;
        int idx = 1;
        while(!pq.empty())
        {
            int num1 = pq.top().first;
            int num2 = pq.top().second;
            arr[idx++][j] = num2;
            arr[idx++][j] = num1;
                
            pq.pop();
        }
        idx--;
        size.push_back(idx);
    }
    sort(size.begin(), size.end());
    return size.back();
}
int solve()
{
    int Time = 0;
    int maxRow = 3, maxColumn = 3;
    while(1)
    {
        if(arr[r][c]==k) return Time;
        if(Time > 100)
        {
            return -1;
        }
        if(maxRow>=maxColumn)
        {
            maxColumn = r_operation(maxRow, maxColumn);
            Time++;
        }
        else
        {
            maxRow = c_operation(maxRow, maxColumn);
            Time++;
        }
        
    }

    return -1;
}
int main()
{
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << solve() << "\n";
}