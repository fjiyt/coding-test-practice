#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int L, C;
vector <char> v;
vector <int> check;
priority_queue <string, vector<string>, greater<string>> pq;

int main()
{
    cin >> L >> C;
    // 조합
    for(int i=0; i<C; i++)
    {
        char c;
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<C-L; i++)
    {
        check.push_back(0);
    }
    for(int i=C-L; i<C; i++)
    {
        check.push_back(1);
    }
    
    do{
        // cout << check[0] << "\n";
        string str = "";
        int a=0, b=0;
        for(int i=0; i<C; i++)
        {
            if(check[i]==1)
            {
                if(v[i]=='a' || v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u') {
                    a++;
                }
                else b++;
                str += v[i];
            }
        }

        if(a>=1 && b>=2) pq.push(str);

    }while(next_permutation(check.begin(),check.end()));

    while(!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
}