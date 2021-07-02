#include <iostream>
#include <stdio.h>

using namespace std;
long long d[92]={0,};

long long Fibonacci(int num)
{
    if(num==1) return 1;
    else if(num==2) return 1;

    if(d[num]!=0) return d[num];

    return d[num] = Fibonacci(num-1) + Fibonacci(num-2);
}
int main()
{
    int N;
    cin >> N;

    long long f = Fibonacci(N);
    cout << f << "\n";

    return 0;
}