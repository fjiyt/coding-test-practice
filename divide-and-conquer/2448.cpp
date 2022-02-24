#include <iostream>

using namespace std;
int N;
char arr[3500][6500];
char DB[][6]=
{
    "  *  ",
    " * * ",
    "*****"
};

void solve(int size,int y, int x)
{
    if(size==1)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<5; j++)
            {
                arr[y+i][x+j] = DB[i][j];
            }
        }
        return;
    }
    solve(size/2,y,x+3*size/2);
    solve(size/2,y+3*size/2, x);
    solve(size/2,y+3*size/2, x+3*size);
}
int main()
{
    cin >> N;

    solve(N/3,0,0);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<2*N-1; j++)
        {
            cout << ((arr[i][j]=='*') ? '*' : ' ');
        }
        cout << "\n";
    }
}