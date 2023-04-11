#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int> s;
    s.insert(10);
    s.insert(20);
    s.insert(50);
    s.insert(60);

    set<int>::iterator it;

    s.insert(10);

    for(it=s.begin(); it!=s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n";

    it = s.find(30);
    if(it!=s.end())
    {
        cout << *it << " 존재" << "\n";
    }
    else{
        cout << "존재x\n";
    }
}