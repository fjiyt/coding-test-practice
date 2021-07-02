#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int num;
    cin >> num;

    long long path[num-1];
    long long pay[num];
    long long min_cost=0; //총 금액

    int i;

    for(i=0; i<num-1; i++)
    {
        cin >> path[i];
    }
    for(i=0; i<num; i++)
    {
        cin >> pay[i];
    }
    for(i=0; i<num-1; i++)
    {
        min_cost += pay[i]*path[i];
        path[i]=0;
        
        for(int j=i+1; j<num-1; j++)
        {
            if(pay[i] < pay[j]){
                min_cost += pay[i]*path[j];
                path[j]=0;
            }
            else {
                i=j-1;
                break;
            }
        }
    }
    
    printf("%lld\n",min_cost);
    return 0;
}