#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int arr[17][17];
int N;

int calculate(vector <int> &v)
{
    int total=0;
    for(int i=0; i<N/2; i++)
    {
        for(int j=0; j<N/2; j++)
        {
            int s = v[i];
            int e = v[j];
            if(s!=e && arr[s][e]!=0)
            {
                total += arr[s][e];
            }
        }
    }
    return total;
}

int Solve()
{
    vector <bool> v(N/2, false);
    v.insert(v.end(), N/2, true);
    vector <int> A;
    vector <int> B;
    int min_diff = 1000000;
    do{
        A.clear();
        B.clear();
        for(int i=0; i<N; i++)
        {
            if(v[i]) A.push_back(i+1);
            else B.push_back(i+1);
        }
        int diff = abs(calculate(A)-calculate(B));
        min_diff = min(min_diff, diff);
    }while(next_permutation(v.begin(), v.end()));

    return min_diff;
}
int main()
{
    int Case;
    cin >> Case;

    for(int i=0; i<Case; i++)
    {
        cin >> N;

        for(int j=1; j<=N; j++)
        {
            for(int k=1; k<=N; k++)
            {
                cin >> arr[j][k];
            }
        }

        int ret = Solve();
        cout << "#" << i+1 << " " << ret << "\n";
        for(int j=1; j<=16; j++)
        {
            for(int k=1; k<=16; k++)
            {
                arr[j][k] = 0;
            }
        }
    }
}