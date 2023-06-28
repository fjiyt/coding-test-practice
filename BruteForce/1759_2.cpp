#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int L, C;
vector <char> v;
vector <int> check;
string str;

void combination(int start, int cnt)
{
    if(cnt==L)
    {
        int a = 0, b=0;
        for(int i=0; i<L; i++)
        {
            if(str[i]=='a' || str[i]=='e'|| str[i]=='i'|| str[i]=='o'|| str[i]=='u') a++;
            else b++;
        }
        if(a>=1 && b>=2) cout << str << "\n";
        return;
    }

    for(int i=start; i<C; i++)
    {
        string tmp = str;
        str += v[i];
        combination(i+1, cnt+1);
        str = tmp;
    }
}
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

    combination(0,0);
}