#include <iostream>
#include <list>

using namespace std;

int main()
{
    list <int> a;

    a.push_back(22);
    a.push_back(33);
    a.push_front(11);
    a.push_back(44);
    a.push_back(55);
    
    list <int>::iterator it;

    for(it=a.begin(); it!=a.end(); it++)
    {
        cout << *it << "\n";
    }

    a.pop_front();
    a.pop_back();

    for(it=a.begin(); it!=a.end(); it++)
    {
        cout << *it << "\n";
    }

    cout << a.size() << "\n";
    cout << a.empty() << "\n";
    cout << a.front() << "\n";
    cout << a.back() << "\n";

    cout << "\n\n";

    it++;
    it++;
    it--;
    cout << *it << "\n\n";
    a.insert(it, 5555);
    for(it = a.begin(); it!=a.end(); it++)
    {
        cout << *it << "\n";
    }
}