#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> s;
    s.push(4);
    s.push(3);
    s.push(6);
    s.pop();
    s.push(11);
    s.push(9);
    s.pop();

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";
}