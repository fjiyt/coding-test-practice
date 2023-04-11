#include <iostream>
#include <set>

using namespace std;
int P;

int main()
{
    cin >> P;
    while(P--)
    {
        int t;
        cin >> t;
        set <int, greater<int>> s;

        int tall=0, cnt=0;
        cin >> tall;
        s.insert(tall);
        for(int i=1; i<20; i++)
        {
            cin >> tall;
            for(auto it=s.begin(); it!=s.end(); it++)
            {
                if(*it > tall) {
                    cnt++;
                }
                else{
                    s.insert(tall);
                    break;
                }
            }
            if(s.find(tall)==s.end()) s.insert(tall);
        }
        cout << t << " " << cnt << "\n";
    }
}