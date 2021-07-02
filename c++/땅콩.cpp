#include <iostream>
#include <stdbool.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10000] = {0,};
int min_length = 1000000;
int N, M, E;
bool isVisited[10000] = {false,};

void dfs(vector <int> &v)
{
    if(v.size()==M)
    {
        int min_v=E, max_v=E;
        int dis = 0;
        for(int i=0; i<v.size(); i++)
        {
            min_v = min(min_v,v[i]);
            max_v = max(max_v,v[i]);
        }

        int length = max_v - min_v;
        min_length = min(min_length, length);
    }

    for(int i=0; i<N; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            v.push_back(arr[i]);
            dfs(v);
            v.pop_back();
            isVisited[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> E;

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    vector <int> v;
    dfs(v);

    cout << min_length << "\n";
    return 0;
}