#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v1;
    vector <int> v2(6);
    vector <int> v3(4,1);
    vector <int> v4 = {1,2,3,4,5};

    v4.push_back(6);
    v4.push_back(7);

    v4.pop_back();

    v4.clear();

    for(vector <int>::iterator it=v3.begin(); it!=v3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}