#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a>b;
}
int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long cnt,day;
    cin >> cnt;
    long long i,j;
    long long profit;
    long long max_index=0;

    while(cnt--){
        cin >> day;
        int input[day];
        int order[day];

        for(i=0; i<day; i++)
        {
            cin >> input[i];
            order[i]=input[i];
        }
        sort(order,order+day,compare);

        max_index=-1;
        profit=0;
        for(i=0; i<day; i++)
        {
            if(order[0]==input[i] )
            {
                for(j=max_index+1; j<i; j++)
                {
                    profit += order[0]-input[j];
                }
                max_index = i;
                if(max_index == day-1){ //마지막일 경우
                    break;
                }
                int k=0;
                for(j=max_index+1; j<day; j++) //다시 정렬
                {
                  //  if(max_index == -1) cin >> input[j];
                    order[k]=input[j];
                }
                sort(order,order+day-(max_index+1),compare);
            }
        }
        cout << profit << "\n";
    }

    return 0;
}