#include <iostream>

using namespace std;
int num[51];
int calc[51];
bool isVisited[51];
string str;

void solve(int start, int cnt)
{
    
}
int main()
{
    cin >> str;
    int cnt = 0;
    for(int i=0; i<str.length(); i++)
    {
        int tmp = 0;
        while(!str[i]=='-' && !str[i]=='+')
        {
            tmp *= 10;
            tmp += int(str[i]);
            i++;
        }
        num[cnt] = tmp;
        cnt++;
        if(str[i]=='-' || str[i]=='+') calc[cnt] = str[i];
    }

    solve(0,0);w
}