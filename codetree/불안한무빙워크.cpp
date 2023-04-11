#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <pair<int,int>> moving(201);

void Print()
{
    for(int i=0; i<2*n; i++)
    {
        cout << "(" << moving[i].first << "," << moving[i].second << ")" << " ";
    }
    cout << "\n";
}
void rotate()
{
    pair <int,int> tmp;

    for(int i=2*n-1; i>0; i--)
    {
        if(i==2*n-1)
        {
            tmp.first = moving[i].first;
            tmp.second = moving[i].second;
        }
        moving[i].first = moving[i-1].first;
        moving[i].second = moving[i-1].second;
    }

    moving[0].first = tmp.first;
    moving[0].second = tmp.second;
}
void move()
{
    for(int i=n-1; i>=0; i--)
    {
        if(moving[i].second==1)
        {
            int next = i+1;
            if(next==n){
                moving[i].second = 0;
            }
            else{
                if(moving[next].second==0 && moving[next].first > 0)
                {
                    moving[next].second = 1;
                    moving[next].first--;
                    moving[i].second=0;
                }
            }
        }
    }
}

void solve()
{
    int count = 0;
    while(1)
    {
        int zeros = 0;
        count++;
        // 무빙워크 회전
        rotate();
        // 무빙워크에 타있는 사람 이동
        move();
        // 1번칸에 사람 올리기
        if(moving[0].second==0 && moving[0].first > 0)
        {
            moving[0].second=1;
            moving[0].first--;
        }
        
        if(moving[n-1].second==1)
        {
            moving[n-1].second=0;
        }
        for(int i=0; i<2*n; i++)
        {
            if(moving[i].first==0) zeros++;
        }

        if(zeros >= k) {
            cout << count << "\n";
            return;
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<2*n; i++)
    {
        cin >> moving[i].first;
    }

    solve();
}