#include <iostream>

using namespace std;

int main()
{
    bitset<10> a(76), b(44);

    cout << (a&b) << "\n";
    cout << (a|b) << "\n";
    cout << (a^b) << "\n";
    cout << (a>>2) << "\n";
    cout << (~a) << "\n";
    cout << (~b) << "\n";
}