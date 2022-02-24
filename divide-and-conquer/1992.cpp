#include <cstdio>

using namespace std;
int N;
int arr[65][65];

void solve(int size, int x, int y)
{
    if(size==1)
    {
        printf("%d", arr[x][y]);
        return;
    }
    bool flag = true;

    for(int i=x; i<x+size; i++)
    {
        if(!flag) break;
        for(int j=y; j<y+size; j++)
        {
            if(arr[x][y]!=arr[i][j]) {
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        printf("%d", arr[x][y]);
        return;
    }

    int nsize = size/2;
    
    printf("(");
    solve(nsize, x, y);
    solve(nsize, x, y+nsize);
    solve(nsize, x+nsize, y);
    solve(nsize, x+nsize, y+nsize);
    printf(")");

    return;
}
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    solve(N,0,0);
    printf("\n");

    return 0;
}