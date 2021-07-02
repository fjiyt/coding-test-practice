#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define MAX 10002

using namespace std;
int arr[MAX] = {0,};
int N; //트리 노드 개수

int seperate_node(int start, int end) //노드를 오른쪽 왼쪽으로 구분
{
    if(arr[start]<=0 && arr[end]<=0) return 0;

    for(int i=start+1; i<end; i++)
    {
        if(arr[start] < arr[i]) //이때부터 right node
        {
     //       printf("i : %d\n",i);
            return i;
        }
    }
    return end;
}

void makePostTree(int start, int end)
{
    if(start >= end) return;

    int center = seperate_node(start,end);
    printf("%d %d %d\n",start,center,end);

    makePostTree(start+1,center);
//    printf("a\n");
    makePostTree(center,end);
    printf("%d\n",arr[start]);

    return;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i=0;
    int input;
    
    while(cin >> input)
    {
        arr[i] = input;
        i++;
    }

    N = i;
    makePostTree(0,N);

    return 0;
}