#include <iostream>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

int getParent(int parent[], int a)
{
    if(parent[a] == a)
    {
        return a;
    }
    return parent[a] = getParent(parent, parent[a]);
}
void unionParent(int parent[], int a, int b)
{
    a = getParent(parent,a);
    b = getParent(parent,b);

    if(a<b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
    
}
int findParent(int parent[], int a, int b)
{
    a = getParent(parent,a);
    b = getParent(parent,b);
    if(a==b)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;

    int parent[N];
    for(int i=0; i<=N; i++)
    {
        parent[i] = i;
    }

    for(int i=0; i<M; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if(op==0)
        {
            unionParent(parent, a, b);
        }
        else if(op==1)
        {
            int ret = findParent(parent,a,b);
            if(ret==1)
            {
                cout << "YES" <<"\n";
            }
            else cout << "NO" << "\n";
        }
    }
}