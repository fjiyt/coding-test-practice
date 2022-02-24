#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int *arr = new int[N];
    int *DP = new int[N];
    vector <int> Sort;
    int num;
    vector<int>::iterator it;
    stack<int> Answer;
    int index = 0;
    int max_dp = 0;

    for(int i=0; i<N; i++)
    {
        cin >> num;
        arr[i] = num;

        if(Sort.empty())
        {
            DP[i] = 1;
            Sort.push_back(arr[i]);
        }
        else{
            if(Sort.back() < arr[i])
            {
                Sort.push_back(arr[i]);
                DP[i] = Sort.size();
            }
            else{
                it = lower_bound(Sort.begin(), Sort.end(), arr[i]);
                *it = arr[i];
                DP[i] = it - Sort.begin() + 1;
            }
        }
        if(max_dp < DP[i])
        {
            max_dp = DP[i];
            index = i;
        }
    }

    Answer.push(arr[index]);
    for(int i=index-1; i>=0; i--)
    {
        if(arr[i] < arr[index] && DP[index] == DP[i] + 1)
        {
            Answer.push(arr[i]);
            index = i;
        }
    }

    cout << Answer.size() << "\n";
    while(!Answer.empty())
    {
        cout << Answer.top() << " ";
        Answer.pop();
    }
    cout << "\n";
}