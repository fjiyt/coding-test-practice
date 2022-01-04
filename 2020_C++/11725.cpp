#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;
vector<int> v[MAX];
bool visited[MAX] = {
    false,
};
int parentNum[MAX] = {
    0,
};

void findParent(int node)
{
    visited[node] = true;

    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];

        if (!visited[next])
        {
            parentNum[next] = node;
            findParent(next);
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2;

        cin >> node1 >> node2;

        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    findParent(1);

    for (int i = 2; i <= N; i++)
    {
        cout << parentNum[i] << "\n";
    }

    return 0;
}