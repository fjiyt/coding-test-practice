#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdbool.h>
#include <cmath>

using namespace std;

char sign[10]={0,};
char arr[10] = {0,1,2,3,4,5,6,7,8,9};
bool isVisited[10] = {false,};
long long min_n = 0;
long long max_n = 0;
int K;

void dfs(vector <int> &v)
{
    long long value = 0;
    if(v.size()==K+1)
    {
        for(int i=0; i<K+1; i++)
        {
            value *= 10;
            value += v[i];
        }
        min_n = min(value, min_n);
        max_n = max(value, max_n);
    }
    
    unsigned long int num=0;
    for(int i=0; i<10; i++)
    {
        if(!isVisited[i])
        {
            num = v.size()-1;
            if(sign[num] == '<')
            {
                if(v[num] > arr[i]) continue;
            }
            else if(sign[num] == '>')
            {
                if(v[num] < arr[i]) continue;
            }
            isVisited[i] = true;
            v.push_back(arr[i]);
            dfs(v);
            isVisited[i] = false;
            v.pop_back();
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> K;

    for(int i=0; i<K; i++)
    {
        cin >> sign[i];
    }

    vector <int> v;
    min_n = pow(10, K+1);
    dfs(v);

    cout << max_n << "\n";
    if(min_n < pow(10,K))
    {
        cout << "0";
    }
    cout << min_n << "\n";

    return 0;
}