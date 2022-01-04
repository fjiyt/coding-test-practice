#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) arr[i][j] = 0;
            else arr[i][j] = 1e9;
        }
    }

    for(int i=0; i<m; i++)
    {
        int x,y,cost;
        cin >> x >> y >> cost;

        arr[x][y] = min(arr[x][y],cost);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j]==1e9) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}