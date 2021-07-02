#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int arr[N+1][N+1];
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = 1e9;
        }
    }
    for(int i=0; i<M; i++)
    {
        int x,y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j]=arr[i][k]+arr[k][j];
            }
        }
    }
    int min_dis = 1e9; //최소 거리
    int min_person = N+1;//최소인 사람
    for(int i=1; i<=N; i++)
    {
        int tmp=0;
        for(int j=1; j<=N; j++)
        {
            tmp += arr[i][j];
        }
        if(min_dis > tmp)
        {
            min_dis = tmp;
            min_person = i;
        }
        else if(min_dis == tmp)
        {
            min_person = min(min_person, i);
        }
    }

    cout << min_person << "\n";
    return 0;
}