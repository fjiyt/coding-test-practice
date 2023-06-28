#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

vector <pair<string,int>> v;
map <string,int> m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        if(str.length() < M) continue;
        if(m.find(str)!=m.end()) m[str]++;
        else m.insert({str,1});
    }

    for(auto it = m.begin(); it!=m.end(); it++)
    {
        
    }
}