#include <iostream>

using namespace std;

int N;
struct schedult{
    int day;
    int pay;
}s[16];
int result[16];

void Input()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> s[i].day >> s[i].pay;
    }
}

void DP()
{
    for(int i=N; i>0; i--)
    {
        int deadline = i + s[i].day;
        if(deadline > N+1) {
            result[i]=result[i+1];
        }
        else{
            result[i] = max(result[i+1], result[deadline] + s[i].pay);
        }
    }
}
int main()
{
    Input();
    DP();

    cout << result[1] << "\n";
}