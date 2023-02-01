#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector <int> DAU;
int curSum;
int maxSum;
int maxCnt;

void solve()
{
    // 첫번째
    for(int i=0; i<X; i++)
    {
        curSum += DAU[i];
        maxSum = curSum;
        maxCnt = 1;
    }
    //sliding
    for(int i=1; i<N-X+1; i++)
    {
        curSum = curSum - DAU[i-1] + DAU[i+X-1];

        if(curSum == maxSum) maxCnt++;
        else if(curSum > maxSum){
            maxSum = curSum;
            maxCnt=1;
        }
    }

    if(maxSum==0) cout << "SAD\n";
    else cout << maxSum << "\n" << maxCnt << "\n";
}
int main()
{
    cin >> N >> X;
    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        DAU.push_back(num);
    }

    solve();
}