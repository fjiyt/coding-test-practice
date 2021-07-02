#include <iostream>
#include <vector>
#include <stack>

#define MAX 502
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    int x, y;
    int arr[N + 1][N + 1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = 1e9;
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        arr[x][y] = 1;
    }
    for (int k = 1; k <= N; k++) //거점 노드
    {
        for (int i = 1; i <= N; i++) //시작 노드
        {
            for (int j = 1; j <= N; j++) //종료 노드
            {
                if (i == j)
                {
                    arr[i][j] = 0;
                }
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    int cnt = 0;
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (arr[i][j] == 1e9 && arr[j][i] == 1e9)
                break;
        }
        if (j == N + 1)
            cnt++; //i 는 순서가 있다.
    }

    cout << cnt << "\n";
    return 0;
}