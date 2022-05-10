#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector <int> v;
int main()
{
    cin >> N >> L;
    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int now = L;
    
    for(int i=0; i<N; i++)
    {
        if(now >= v[i] && v[i]>0)
        {
            now++;
            v[i]=0;
            i=-1;
        }
    }

    cout << now << "\n";
}