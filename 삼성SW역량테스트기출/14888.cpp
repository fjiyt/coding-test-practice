#include <iostream>
#include <vector>

using namespace std;
int N;
vector <int> num;
int oper[11];
int maxNum=-1000000001;
int minNum=1000000001;
bool isVisited[11] = {false,};

int calculate(vector <int> &v)
{
    int sum = num[0];
    int idx = 1;

    for(int i=0; i<N-1; i++)
    {
        int next = num[idx];
        switch(v[i])
        {
            case 0 :
                sum += next;
                break;
            case 1:
                sum -= next;
                break;
            case 2:
                sum *= next;
                break;
            case 3:
                sum /= next;
                break;
        }

        idx++;
    }

    return sum;
}
void dfs(vector <int> &v)
{
    if(v.size() == N-1)
    {
        int sum = calculate(v);
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }

    for(int i=0; i<N-1; i++)
    {
        if(!isVisited[i])
        {
            v.push_back(oper[i]);
            isVisited[i] = true;
            dfs(v);
            v.pop_back();
            isVisited[i] = false;
        }
    }
}
int main()
{
    vector <int> v;
    cin >> N;
    for(int i=0; i<N; i ++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    int idx = 0;
    for(int i=0; i<4; i++)
    {
        int n;
        cin >> n;
        for(int j=0; j<n; j++)
        {
            oper[idx] = i;
            idx++;
        }
    }

    dfs(v);

    cout << maxNum << "\n";
    cout << minNum << "\n";
}