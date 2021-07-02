#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[13]={0,};
int combi[13] = {0,};

void dfs(int depth, int start)
{
    if(depth == 6)
    {
        for(int i=0; i<6; i++)
        {
            cout << combi[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=start; i<N; i++)
    {
        combi[depth] = arr[i];
        dfs(depth+1, i+1);
    }

    return;
}
int main()
{
    while(1)
    {
        cin >> N;

        if(N==0)
        {
            break;
        }
        for(int i=0; i<N; i++)
        {
            cin >> arr[i];
        }

        dfs(0,0);
        cout << "\n";
    }

    return 0;
}