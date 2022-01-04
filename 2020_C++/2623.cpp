#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int sorts[1001] = {0,};

int getParent(int parent[], int x)
{
    if(parent[x]==x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
    a = getParent(parent,a);
    b = getParent(parent,b);

    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
    a = getParent(parent,a);
    b = getParent(parent,b);
    if(a==b) return 1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;

    int parent[N+1];
    for(int i=1; i<=N; i++)
    {
        parent[i] = i;
    }
    int past, now=0;
    for(int i=0; i<M; i++)
    {
        int T;
        cin >> T;

        past = 0;
        for(int j=0; j<T; j++)
        {
            cin >> now;
            if(past == 0) {
                past = now;
                continue;
            }

            unionParent(parent, past, now);
            past = now;
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++) //제일처음 Parent
    {
        if(getParent(parent,i)==i)
        {
            sorts[cnt]=parent[i];
        }
        cnt++;
    }

    for(int i=1; i<=N; i++)
    {
        
    }

    return 0;
}