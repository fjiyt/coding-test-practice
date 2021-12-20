#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N;
int arr[21][21] = {
    0,
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//자리 저장
vector<pair<int, int>> seat[21];

//좋아하는 친구가 무조건 4명. 4명으로 탐색해야됨
vector<int> bf[21];
int cnt = 0; // 친구 몇명 배치했는지

void searchBestSeat(int me)
{
    queue<int> near_friend;

    while (!near_friend.empty())
    {
        int x = 0, y = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
        }
    }

    //1. bf랑 인접한 칸이 많은 곳

    //2. 인접한 칸 중에서 비어있는 칸이 가장 많은 칸

    //3. 행의 번호가 가장 작은 곳 / 열의 번호가 가장 작은 곳
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N * N; i++)
    {
        int me;
        cin >> me;

        for (int i = 0; i < 4; i++)
        {
            int num;
            cin >> num;
            bf[me].push_back(num);
        }

        searchBestSeat(me);
    }

    //만족도 총합
    return 0;
}
