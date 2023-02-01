#include <iostream>

using namespace std;

int main(void)
{
    int N,F;

    cin >> N >> F;

    int original = N/100;

    for(int i =0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if((original*100 + 10*i + j) % F == 0)
            {
                cout << i << j << "\n";
                return 0;
            }
        }
    }

    return 0;
}