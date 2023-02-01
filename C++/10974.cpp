#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int N;
bool isVisited[9]={false,};

void permutation(vector <int> &v)
{
    if(v.size()==N)
    {
        for(int i=0; i<N; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++)
    {
        if(!isVisited[i])
        {
            v.push_back(i);
            isVisited[i] = true;
            permutation(v);
            v.pop_back();
            isVisited[i] = false;
        }
    }

    return;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> N;

    vector <int> v;
    permutation(v);

    return 0;
}