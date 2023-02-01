#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long cnt,day,profit;
    long long i;
    int input,max;
    cin >> cnt;

    vector<int> v;

    while(cnt--){
        cin >> day;
        for(i=0; i<day; i++)
        {
            cin >> input;
            v.push_back(input);
        }
        max=0;
        profit=0;
        std::vector<int>::reverse_iterator it;
        for(it = v.rbegin(); it != v.rend(); it++){
            if(max < *it){
                max = *it;
            }
            else{
                profit += max - *it;
            }
        }
        cout << profit <<"\n";
        v.clear();
    }
}