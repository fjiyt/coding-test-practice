//중복되는 경우를 줄이는 것이 중요함 
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[22][22];
bool isStartTeam[22]={false,};
int total;
int minDiff=1000;

int startCalc(vector <int> &v)
{
    bool isCalc[22][22] = {false,};
    int sum=0;
    for(int i=0; i<v.size(); i++)
    {
        int p = v[i];
        for(int j=0; j<v.size(); j++)
        {
            int q = v[j];
            if(!isCalc[p][q] && arr[p][q] > 0)
            {
                sum += arr[p][q];
                isCalc[p][q] = true;
            }
        }

    }
    return sum;
}

int linkCalc()
{
    bool isCalc[22][22] = {false,};
    int sum=0;
    vector <int> v;
    for(int i=1; i<=N; i++)
    {
        if(!isStartTeam[i]) v.push_back(i);
    }
    for(int i=0; i<v.size(); i++)
    {
        int p = v[i];
        for(int j=0; j<v.size(); j++)
        {
            int q = v[j];
            if(!isCalc[p][q] && arr[p][q] > 0)
            {
                sum += arr[p][q];
                isCalc[p][q] = true;
            }
        }
    }
    return sum;
}
void dfs(vector <int> &v, int idx)
{
    if(v.size() == N/2)
    {
        int startTotal = startCalc(v);
        int linkTotal = linkCalc();

        minDiff = min(minDiff, abs(startTotal-linkTotal));
    }
    for(int i=idx; i<=N; i++)
    {
        if(!isStartTeam[i])
        {
            v.push_back(i);
            isStartTeam[i]=true;
            dfs(v, i);
            v.pop_back();
            isStartTeam[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector <int> v;
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            total += arr[i][j];
        }
    }

    dfs(v, 1);

    cout << minDiff << "\n";
}