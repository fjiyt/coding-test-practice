#include <iostream>

using namespace std;
int arr[501][501];
int max_sum = 0;

void DFS()
{
}
//ㅜ 모형

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            //DFS

            //ㅜ 모양
        }
    }

    cout << max_sum << "\n";
}