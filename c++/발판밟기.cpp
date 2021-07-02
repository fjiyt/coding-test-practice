#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#include <cstring>

using namespace std;

int arr[101] = {0,};
int max_num = 0;
bool check[101] = {false,};
int N;

int found(int first)
{
    int count=0;
    int next = first;

    for(int i=0; i<101; i++)
    {
        check[i] = false;
    }

    while(!check[next])
    {
        count++;
        check[next] = true;
        next += arr[next];
    }

    return count;
}
int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<3; i++)
    {
        int num = found(i)+1;
        max_num = max(max_num,num);
    }

    cout << max_num << "\n";
    return 0;
}