#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

string origin;
int tmp[65];
long long k;

int main()
{
    cin >> origin >> k;
    int cnt = 0;
    for(int i=0; i<origin.length(); i++)
    {
        if(origin[i] == '2' || origin[i] == '7' || origin[i] == '1' || origin[i] == '6')
        {
            cnt++;
        }
    }
    if(k > pow(2,cnt) || k < 0)
    {
        cout << "-1\n";
        return 0;
    }

    bitset<64> bs(k-1);
    int j=cnt-1;
    for(int i=0; i<origin.length(); i++)
    {
        if(j < -1)
        {
            cout << "-1\n";
            break;
        }
        if(origin[i] == '1' || origin[i] == '6')
        {
            if(bs[j]==0) origin[i] = '1';
            else origin[i] = '6';
            j--;
        }
        else if(origin[i] == '2' || origin[i] == '7')
        {
            if(bs[j]==0) origin[i] = '2';
            else origin[i] = '7';
            j--;
        }
    }
    cout << origin << "\n";
}