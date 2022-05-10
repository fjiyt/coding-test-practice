#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string origin;
vector <string> v;

int main()
{
    cin >> origin;
    int length = origin.length();
    v.push_back(origin);
    for(int i=1; i<length; i++)
    {
        origin.erase(0,1);
        v.push_back(origin);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}