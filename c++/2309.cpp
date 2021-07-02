#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stdbool.h>

using namespace std;

int tall[9] = {0,};
int cnt = 0;
bool isVisited[9] = {false,};

void dfs(vector <int> &v)
{
    if(v.size() == 7 && cnt == 0)
    {
        int sum = 0;
        for(int i=0; i<7; i++)
        {
            sum += v[i];
        }
        if(sum==100)
        {
            sort(v.begin(),v.end());
            for(int i=0; i<7; i++)
            {   
                cout << v[i] << "\n";
            }
            cnt ++;
        }
        return;
    }

    else if(cnt > 0)
    {
        return;
    }

    for(int i=0; i<9; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            v.push_back(tall[i]);
            dfs(v);
            v.pop_back();
            isVisited[i] = false;
        }
    }
    return;
}

int main()
{
    for(int i=0; i<9; i++)
    {
        cin >> tall[i];
    }

    vector <int> v;
    dfs(v);

    return 0;
}