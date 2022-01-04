#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[9] = {0,};
bool isVisited[9] = {false,};
int max_n = 0;

int absol_sum(vector <int> &v)
{
    int sum = 0;
    for(int i = N-1; i > 0 ; i--)
    {
        if(v[i] > v[i-1])
        {
            sum += v[i]-v[i-1];
        }
        else
        {
            sum += v[i-1] - v[i];
        }
    }

    return sum;
}
void dfs (vector <int> &v)
{
    if(v.size() == N)
    {
        int sum = absol_sum(v);
        max_n = max(max_n, sum);
        return;
    }

    for(int i=0; i<N; i++)
    {
        if(!isVisited[i])
        {
            v.push_back(arr[i]);
            isVisited[i] = true;
            dfs(v);
            v.pop_back();
            isVisited[i] = false;
        }
    }
}
int main()
{
    vector <int> v;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    dfs(v);

    cout << max_n << "\n";
    return 0;
}