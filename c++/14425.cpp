#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

set <string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    int cnt=0;

    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    for(int i=0; i<M; i++)
    {
        string str2;
        cin >> str2;

        if(s.find(str2)!=s.end())
        {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}