#include <iostream>
#include <vector>

using namespace std;
int N, M, knowing_num;
int parent[51], isTrue[51], party[51][51];
int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}
void union_parent(int x, int y)
{
    parent[find(y)] = find(x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    cin >> knowing_num;
    for (int i = 0; i < knowing_num; i++)
    {
        cin >> isTrue[i];
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        cin >> party[i][0];
        for (int j = 1; j < num; j++)
        {
            cin >> party[i][j];
            union_parent(party[i][0], party[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        bool flag = true;
        for (int j = 0; j < knowing_num; j++)
        {
            if (find(party[i][0]) == find(isTrue[j]))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }

    cout << cnt << "\n";
}