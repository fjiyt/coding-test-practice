#include <iostream>
#include <queue>

using namespace std;

int r,c,k;
int arr[102][102];
int maxRow, maxColumn;
priority_queue <pair <int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

void r_operation()
{
    maxColumn = 0;
    for(int i=1; i<=maxRow; i++)
    {
        int cnt[101] = {0,};
        int j = 1;
        while(arr[i][j]>0)
        {
            cnt[arr[i][j]]++;
            j++;
        }
        for(int k=1; k<=100; k++)
        {
            if(cnt[k] > 0)
            {
                pq.push(make_pair(cnt[k], k));
            }
        }
        int s = pq.size();
        if(s*2 > 100) maxColumn = 100;
        else maxColumn = max(maxColumn, s * 2);
        for(int k=1; k<=100; k++)
        {
            if(pq.empty()) arr[i][k] = 0;
            else{
                int num1 = pq.top().first;
                int num2 = pq.top().second;
                arr[i][k] = num2;
                arr[i][k+1] = num1;
                //cout << i <<" " << k << " " << num2 << num1 << "\n";
                pq.pop();
                k++;
            }
        }
    }
    
}
void c_operation()
{
    maxRow = 0;
    for(int j=1; j<=maxColumn; j++)
    {
        int cnt[101] = {0,};
        int i = 1;
        while(arr[i][j]>0)
        {
            cnt[arr[i][j]]++;
            i++;
        }
        for(int k=1; k<=100; k++)
        {
            if(cnt[k] > 0)
            {
                pq.push(make_pair(cnt[k], k));
            }
        }
        int s = pq.size();
        if(s*2 > 100) maxRow = 100;
        else maxRow = max(maxRow, s*2);
        for(int k=1; k<=100; k++)
        {
            if(pq.empty()) arr[k][j] = 0;
            else
            {
                int num1 = pq.top().first;
                int num2 = pq.top().second;
                arr[k][j] = num2;
                arr[k+1][j] = num1;
                pq.pop();
                //cout << "here : " << num2 << num1 << "\n";
                k++;
            }
        }
    }
}
int solve()
{
    int Time = 0;
    maxRow = 3, maxColumn = 3;
    while(1)
    {
        if(arr[r][c]==k) return Time;
        if(Time > 100)
        {
            return -1;
        }
        if(maxRow>=maxColumn)
        {
            r_operation();
            Time++;

            //cout << "r : " << Time << " " << arr[r][c] << "\n";
        }
        else
        {
            c_operation();
            Time++;
            //cout << "c : " << Time << " " << arr[r][c] << "\n";
        }
        for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
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