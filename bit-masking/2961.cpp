#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N;
vector <pair<int,int> > taste;
int min_diff = 1000000001;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int first, second;
        cin >> first >> second;
        taste.push_back(make_pair(first, second));
    }

    int cnt = pow(2, N)-1;
    for(int i=1; i<=cnt; i++)
    {
        int tmp = i;
        int idx = 0;
        int sour = 1;
        int bitter = 0;
        while(tmp > 0)
        {
            if(tmp%2 == 1){
                sour *= taste[idx].first;
                bitter += taste[idx].second;
            }
            tmp /= 2;
            idx++;
        }
        min_diff = min(min_diff, abs(sour - bitter));
    }

    cout << min_diff << "\n";
} 