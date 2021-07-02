#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct st{
    long long int row;
    long long int col;
    long long int value;
};

long long int arr[502][502] = {0,};
int M, N;
long long int cnt = 0;
st sor[599999];
int DP[502][502] = {0,};

bool compare(st x, st y)
{
    return x.value > y.value;
}
void Input()
{
    cin >> M >> N;
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            sor[cnt].value = arr[i][j];
            sor[cnt].row = i; //행
            sor[cnt].col = j; //열
            cnt++;
        }
    }

    sort(sor,sor+cnt,compare); // 이거 때문에 틀림
}

void Solution()
{
    int r, c;

    for(long long int i=0; i<cnt; i++)
    {
        r = sor[i].row;
        c = sor[i].col;

        if(r==1 && c==1) DP[1][1] = 1;
        else{
            if(arr[r][c] != arr[r-1][c]) DP[r][c] += DP[r-1][c];
            if(arr[r][c] != arr[r+1][c]) DP[r][c] += DP[r+1][c];
            if(arr[r][c] != arr[r][c-1]) DP[r][c] += DP[r][c-1];
            if(arr[r][c] != arr[r][c+1]) DP[r][c] += DP[r][c+1];
        }
    }
}

void Solve()
{
    Input();
    Solution();

    cout << DP[M][N] << "\n";

    return;
}

int main()
{
    Solve();

    return 0;
}