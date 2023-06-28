#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while(1)
    {
        int l1=0,l2=0,l3=0;
        cin >> l1 >> l2 >> l3;
        if(!l1&&!l2&&!l3) break;

        int total = l1+l2+l3;

        int max_l = max(l1,l2);
        max_l = max(max_l,l3);

        int r = total - max_l;
        if(r <= max_l)
        {
            cout << "Invalid" << "\n";
            continue;
        }

        if(l1==l2 && l2==l3) {
            cout << "Equilateral\n";
            continue;
        }
        else if(l1==l2 || l1==l3 || l2==l3)
        {
            cout << "Isosceles\n";
            continue;
        }
        else
        {
            cout << "Scalene\n";
            continue;
        }
    }
}