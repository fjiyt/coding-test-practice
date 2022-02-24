#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;
int DP[1001];
vector <int> LIS[1001];
vector <int> Answer;

void solve()
{
    Answer.push_back(v[0]);
    for(int i=0; i<N; i++)
    {
        LIS[i].push_back(v[i]);
        DP[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(v[i] > v[j])
            {
                if(DP[i] < DP[j] + 1)
                {
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(v[i]);
                    DP[i] = DP[j] + 1;
                }
            }
        }
        if(Answer.size() < LIS[i].size())
        {
            Answer = LIS[i];
        }
    }

    cout << Answer.size() << "\n";
    for(int i=0; i<Answer.size(); i++) cout << Answer[i] << " ";
    cout << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    solve();
}