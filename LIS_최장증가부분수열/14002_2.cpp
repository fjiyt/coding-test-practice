#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <int> v;
vector <int> LIS[1001];
vector <int> Answer;
int DP[1001];

void solve()
{
    Answer.push_back(v[0]);
    for(int i=0; i<N; i++)
    {
        LIS[i].push_back(v[i]);
        DP[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(v[j]<v[i])
            {
                if(DP[i] < DP[j]+1)
                {
                    DP[i] = DP[j]+1;
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(v[i]);
                }
            }
        }

        if(Answer.size() < LIS[i].size())
        {
            Answer.clear();
            Answer = LIS[i];
        }
    }

    cout << Answer.size() << "\n";
    for(int i=0; i<Answer.size(); i++)
    {
        cout << Answer[i] << " ";
    }
    cout << "\n";
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    solve();
}