#include <iostream>
#include <vector>

using namespace std;

int main()
{
    pair<int,int> p1;
    cout << p1.first << " " << p1.second << "\n";

    p1 = make_pair(1,2);
    p1 = {3,4};
    cout << p1.first << " " << p1.second << "\n";

    pair <pair<int,int>, pair<int,int> > p2=make_pair(make_pair(1,2), make_pair(3,4));

    cout << p2.first.first << " " << p2.first.second << "\n";
    cout << p2.second.first << " " << p2.second.second << "\n";

}