#include <iostream>
#include <vector>

#define MAX 500001

using namespace std;
vector<int> v[MAX];
bool visited[MAX];
int total = 0;

void findParent(int node, int depth)
{
    int cnt = 0;
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];

        if (!visited[next])
        {
            cnt++;
            findParent(next, depth + 1);
        }
    }
    if (!cnt)
    {
        total += depth;
    }
    return;
}
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    findParent(1, 0);

    if (total % 2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}