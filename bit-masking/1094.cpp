#include <iostream>

#define Stick 64
using namespace std;

int main()
{
    int x;
    cin >> x;

    //가장 짧은 막대의 길이
    int min_stick = Stick;
    int cnt = 1;
    int sum = Stick;
    while(sum > x)
    {
        int half = min_stick >> 1;
        int tmp = sum - half;
        min_stick >>= 1;
        if(tmp >= x)
        {
            sum = tmp;
        }
        else{
            cnt++;
        }
    }
    if(sum == x) cout << cnt << "\n";
}